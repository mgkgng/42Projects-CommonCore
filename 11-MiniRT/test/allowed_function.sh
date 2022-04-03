#!/bin/sh
# ########################################################################## #
#                                                                            #
#                                                        :::      ::::::::   #
#   allowed_function.sh                                :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: GlaceCoding <github.com/GlaceCoding>       +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2021/10/13 12:10:10 by GlaceCoding       #+#    #+#             #
#   Updated: 2021/11/08 12:04:24 by GlaceCoding      ###   ########.fr       #
#                                                                            #
# ########################################################################## #

cd "$(git rev-parse --show-cdup)"

FOLDER_C_FILES="./srcs*"
HEAD="./includes/"

find . -type f -iname "*.c" -path "$FOLDER_C_FILES" -exec gcc -I "$HEAD" -c -fno-builtin -fno-stack-protector {} ";"

used=$(find . -type f -iname "*.o" -path "$FOLDER_C_FILES" -execdir nm -uA {} ";" | sed 's/\(.*\): \_/\1:/g' | sed 's/\.o:/.c:/')
myfc=$(find . -type f -iname "*.o" -path "$FOLDER_C_FILES" -execdir nm -UA {} ";" | sed 's/\(.*\): [0-9a-f]* [Tt] \_/\1:/g' | sed 's/\.o:/.c:/')

rm -f *.o

echo "$used"
echo "#declared function\n\n$myfc" > test/.my_declared_function
for scope in $used; do
	match=$(grep -Fx "$scope" test/.allowed_function)

	if [ "$match" != "$scope" ]; then
		fcname=$(echo "$scope" | cut -d ":" -f2)
		match=$(grep -oE ":$fcname$" test/.my_declared_function)
		if [ "$match" != ":$fcname" ]; then
			match=$(grep -Fx "*:$fcname" test/.allowed_function)
			if [ "$match" != "*:$fcname" ]; then
				echo -e "KO.\nForbidden function $fcname:\n\n\t$scope"
				exit 1
			fi
		fi
	fi
done

exit 0

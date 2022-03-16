#!bin/zsh

# fast `brew link readline`

LIB_FOLDER=vendor

TEMP_FOLDER=$LIB_FOLDER/.tmp_readline-install/
READLINE_PATH=$LIB_FOLDER/readline/

ARCHIVE=$LIB_FOLDER/readline-8.1.tar.gz
INSTALLER=$LIB_FOLDER/readline-8.1
BASEDIR=$(pwd)
curl -k https://ftp.gnu.org/gnu/readline/readline-8.1.tar.gz > $ARCHIVE

tar -xf $ARCHIVE -C vendor/
mkdir -p $READLINE_PATH
cd $READLINE_PATH
READLINE_PATH=$(pwd)
cd $BASEDIR
mkdir -p $TEMP_FOLDER

cd $TEMP_FOLDER
../../$INSTALLER/configure --prefix=$READLINE_PATH

cd $BASEDIR
make -C $TEMP_FOLDER
make -C $TEMP_FOLDER install
make -C $TEMP_FOLDER clean
rm -rf $TEMP_FOLDER $ARCHIVE $INSTALLER

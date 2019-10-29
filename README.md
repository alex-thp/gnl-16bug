alors j'ai rajouter #define BUFFER_SIZE 16 a gnl.h
et ensuite compiler avec gcc - g les ficheiers .c
puis tu lance valgrind ./a.out gnl.c
tu verras d'ou viennent tes invalid read
ou write
il y a de forte chance que ca soit dans tes fonctions libft

rm -rf $HOME/.brew && git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew && echo 'export PATH=$HOME/.brew/bin:$PATH' >> $HOME/.zshrc && source $HOME/.zshrc && brew update

alors peut tu compiler avec le flag -g et ensuite lancer un
valgrind ./executable
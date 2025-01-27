FROM ubuntu:latest

WORKDIR /app
ENV HOME=/home/ubuntu

RUN apt-get update && apt-get install -y \
    git \
    wget \
    tar \
    xz-utils \
    vim \
    gdb \
    gcc \
    valgrind # valgrind --leak-check=full ./your_program

RUN wget https://github.com/pwndbg/pwndbg/releases/download/2025.01.20/pwndbg-lldb_2025.01.20_arm64.tar.xz && \
    tar -v -xf pwndbg-lldb_2025.01.20_arm64.tar.xz
ENV PATH="/app/pwndbg/bin:${PATH}" 

COPY binary_search_tree.c /app
COPY binary_search_tree.c /app

WORKDIR $HOME
RUN git clone https://github.com/scwuaptx/Pwngdb.git
RUN cp ./Pwngdb/.gdbinit $HOME

RUN echo "alias ..='cd ..'" >> $HOME/.bashrc  
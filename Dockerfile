
FROM ubuntu:latest
RUN apt-get update && \
    apt-get install -y build-essential && \
    apt-get install -y gcc-10 g++-10 && \
    rm -rf /var/lib/apt/lists/*
WORKDIR /final
COPY . .
RUN make finalProject
RUN chmod +x finalProject
ENTRYPOINT [ "./finalProject" ]
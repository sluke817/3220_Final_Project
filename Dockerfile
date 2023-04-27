FROM danger89/cmake
WORKDIR /final
COPY . .
RUN make
CMD ["make run"]
FROM danger89/cmake
WORKDIR /final
COPY . .
CMD ["/bin/bash"]
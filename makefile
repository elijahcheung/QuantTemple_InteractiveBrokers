CXX=g++
CXXFLAGS=-DIB_USE_STD_STRING -Wall -Wno-switch
ROOT_DIR=.
BASE_SRC_DIR=${ROOT_DIR}/src
INCLUDES=-I${ROOT_DIR}/Shared/ -I${BASE_SRC_DIR}
OUTPUT=${ROOT_DIR}/bin
TARGET= QuantTrade

$(TARGET):
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o ${OUTPUT}/EClientSocketBase.o -c $(BASE_SRC_DIR)/EClientSocketBase.cpp -g
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o ${OUTPUT}/EPosixClientSocket.o -c $(BASE_SRC_DIR)/EPosixClientSocket.cpp -g
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o ${OUTPUT}/EPosixClientSocket.o -c $(BASE_SRC_DIR)/EPosixClientSocket.cpp -g
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o ${OUTPUT}/EPosix.o -c $(BASE_SRC_DIR)/EPosix.cpp -g
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o ${OUTPUT}/QuantTrade.o -c $(BASE_SRC_DIR)/QuantTrade.cpp -g
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o ${OUTPUT}/Main.o -c $(BASE_SRC_DIR)/Main.cpp -g
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ ${OUTPUT}/EClientSocketBase.o ${OUTPUT}/EPosixClientSocket.o ${OUTPUT}/EPosix.o ${OUTPUT}/QuantTrade.o ${OUTPUT}/Main.o -g

clean:
	rm -rf $(TARGET) ${OUTPUT}/*.o


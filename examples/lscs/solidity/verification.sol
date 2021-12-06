pragma ton-solidity >=0.30.0;
pragma AbiHeader pubkey;

contract VerifyGroth16 {
    bytes public m_proof;

    function setProof(bytes value) public {
        require(msg.pubkey() == tvm.pubkey(), 150);
        tvm.accept();
        //m_proof = value;
        m_proof = hex"a1ae4823125c65067deff465594783e9ede209314b370ea17bb239ec48d740550cd5dbdb913ad2398a81ca6b9c3507c0ad353591edd43f17ece8e6f6d734e53a5cc647573fe67f73d36971ea7dc8ec7cc2d032016a794f51a79b523f41e3cea60300b407371d5f3e37c4cc3e6713c2304e0c76b764bbb5afe7885138241234a6c17c14364a08d755794090739cb159d2b5c1eec1e3f76383d8367335ab66ed99e9c643800a41f73dfe422c9dcc36e9494e81a80f2abe3ff75ec19b300edc9f54000000003c0037f51e28b27124228ff8f14387feb9bc9dc24f7aaae33068473c102f12638aae68c8fd54b5831ec51b7a26d8af174d0575bad425730fcc8f8952778db944adde1481c51dcc02f7b41607f935de3fae7a3bafabd926b7d08f871cab608207a0fb58d5b91289b87f58fe5346b9ec6ac94087f1b37f51c37b2e6ef424b378f581180c34e34349dde1d8d6132c5a5e1067c23be7c34f31ebe969661585eb7cbd51a279b22175bf0caedeaf649f99b71745020d3de9cd8b02acfcec687a662c0e0e3b90f9d69396178a9e95bfcfdf5b9b961d0994f0177f1ca37d55435874dd4a268fe877d65fd88b164b9e65a424690f654c3f6dbe6567654c2e3a64b01e4d7686a80cc0dc5630d48e739ae749c9225c2c6877b38b00dd8f9a06a83ace410e0d5e0c2fe225c973ab13a3c569828bbe9e299a48d393b416934561eb3204686628e2b6798c6855be244bf6e7fc3692f101af0f999959a8d75c565d48a06b76a6c3bfa8c5fa10e2a0e08d56c9e27c4273fbd78cebbce511bd305b9595a0fa6dd10e17f51b062b5c2d681ae7bfee165b653dce2a325e39ec11ccf8523a3099035feab27dafd38367b4d249085ec4dfc1fc1383966cc5b246b75ee61410b86386933753f1bae5e387e53d44302ad9f089c3ddc1073e9494b300b5cab15a03d74732100369542264f1a48ab75ff237abbd48a1b9fd5510c207e11a747242698301acc3a13d71f1cbf13c2143c86e7d4a914d0d16a52c9e8dff47909e64b0d8a701e6215fae6ed80e77b1206df1a2a70c4384b91a5b1d0110de0e551c8b9def9d81f611acc1f7a0c549baed55b1f6ee68f6a4e2a570c4fc3e1e7cdc107add4adbb0b942adf149d074ecb6f8d6a04ef4f729895a154ea222c91b392f5368a18807e927babf3f0adf23003811f60e2c6fcf405b9cbb6d7ef944d85c88147e01e25b0603a080bb964c76c4aa1a040634390b3c4ec3f012846aa4d173ccbcb270b3f90f0fbff0d9431e9281cb429507602158c3fde1099e515506e09f0e34c131b2ddbb0f931d263f1a3ae00831a259786f9fa9174edab2863ef6eb153a557e74b87f367303930898d53a9fbbac4120ed69ba5b1719675bc7c0211e12507d7a7c09112c03915c54af8c08993d71f31a63fac6e4c07d000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    }
    
    function construct_cell(uint begin_index, uint end_index) private view returns (TvmCell obtained_cell){
		uint first_chunk_size = (end_index - begin_index >= 127) ? 127 : (end_index - begin_index);
		uint rest_chunk_size = end_index - begin_index - first_chunk_size;
	    TvmBuilder builder;
	
		for (uint i=0; i<first_chunk_size; i++){
            builder.store(byte(m_proof[begin_index + i]));
        }

        if (end_index - begin_index > 127) {

            TvmCell m_cl_1 = construct_cell(begin_index + first_chunk_size, end_index);
	    
            builder.storeRef(m_cl_1);
		}

		return builder.toCell();
    }
    
    function verify() public view returns (bool is_correct) {
		uint byteblob_size = m_proof.length;
	        
		TvmCell m_cl = construct_cell(0, byteblob_size);
		
		return tvm.vergrth16(m_cl);
    }
}

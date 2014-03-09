#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
void etcParse2Json(std::string etc) //assume key/val does not contain & or = signs
{
    std::size_t pos = etc.find('=');
    std::size_t pos2 = etc.find('&');
    std::size_t pos2prev=-1;
    std::string key ="";
    std::string val="";
    int i,poscount=0, poscount2=0,count=0;;
    int posarr[100]={}, posarr2[100]={};

    for (i =0; i<etc.length(); i++){
	if(etc.at(i) == '&'){	
		posarr[poscount] = i;
		poscount++; 
	}else if(etc.at(i) == '='){
		posarr2[poscount2] = i;
		poscount2++; 
	}    
    }
    for (i=0; i<poscount; i++){
        if(!(posarr[i] > posarr2[i] && posarr[i] < posarr2[i+1])){
		printf("non alternating signs");
		return;
	}
    }
    if( poscount+1 != poscount2 ) {
	printf("no match");
	return;
    }
    while (count <= poscount)
    {
        key = etc.substr(pos2prev+1, pos-pos2prev-1);
	std::string::iterator end_pos = std::remove(key.begin(), key.end(), ' ');
	key.erase(end_pos, key.end());
 	val = etc.substr(pos+1, pos2-pos-1);
        printf("{\n%s:%s\n}\n", key.c_str(), val.c_str());	

	count++;
        pos2prev = pos2;	
	pos = etc.find("=", pos+1);
	if(count  == poscount)
	    pos2 = etc.find("\0",pos2+1);
	else
	    pos2 = etc.find("&", pos2+1);
    }
   
}

int main(){
	std::string teststr = "sellrFlag=1& appID=cine21& purCount=1& prdtBasAmt=4000& cntryCode=KR& prdtCat=%EB%93%9C%EB%9D%BC%EB%A7%88%2C%EA%B3%B5%ED%8F%AC%2F%EC%8A%A4%EB%A6%B4%EB%9F%AC& prdtCatName=%EB%93%9C%EB%9D%BC%EB%A7%88%2C%EA%B3%B5%ED%8F%AC%2F%EC%8A%A4%EB%A6%B4%EB%9F%AC& prdtSubCatName=& chargeType=2& chargePrdUnit=3& chargePrdVal=3& chargeCntVal=0& reqOrdID=& reqEncData=349137a6cc1bfd247ac92383b2b52a31bcff7914a4d23b574cf8379badaa4fade749d7e2d6b179f3d30da43303711d1492c71af65924621fb2a08e02c23565d9ba906fceddee8620e4b92f957a6c77c80c66da80ce9635ac1559884157f7ca4cee92d08b2777e60ad416179e4331fa214d1c5ffa9606460c54cfc01724467621d7e01c082a903e94c3487683d43afc375c66207b5d78a4d9b4ac4f6d37f8d3de8740b2178bd98f45b8ce5170b8d0387a1e4e07512b29e37797e98b1da0618b49ef04699e321541d8fe8f584ce41264e91f9014db848a0c804f0f5a02b67951fa8dd051b7126d0dd80e6079f6449f931763910292210e98a5c4fa1138258abaea";
	etcParse2Json(teststr);
}



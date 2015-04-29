var node_qb = require("./build/Release/node-qb.node");
console.log(node_qb);
var query = '<?xml version="1.0"?>' +
            '<?qbxml version="12.0"?>' +
			'<QBXML>' +
  				'<QBXMLMsgsRq onError="stopOnError">' +
    				'<CompanyQueryRq  requestID="1">' +
      				'</CompanyQueryRq >' +
  				'</QBXMLMsgsRq>' +
			'</QBXML>';
console.log(node_qb.hello("node-qb-demo", query));
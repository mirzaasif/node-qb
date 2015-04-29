var node_qb = require("./build/Release/node-qb.node");
console.log(node_qb);
var query = '<?xml version="1.0"?>' +
            '<?qbxml version="12.0"?>' +
			'<QBXML>' +
  				'<QBXMLMsgsRq onError="stopOnError">' +
    				'<ItemQueryRq  requestID="1">' +
      				'</ItemQueryRq >' +
  				'</QBXMLMsgsRq>' +
			'</QBXML>';
node_qb.hello("node-qb-demo", query, function(response)
{
	console.log(response);
});
colorSet = [
	{
		r: 151,
		g: 255,
		b: 0
	},
	{
		r: 255,
		g: 0,
		b: 151
	},

	{
		r: 0,
		g: 151,
		b: 255
    },
    
    {
        r: Math.floor(102 /4),
        g: Math.floor(153 /4),
        b: Math.floor(194 /4),
    },
    
    {
        r: Math.floor(255 /4),
        g: Math.floor(153 /4),
        b: 0
    },
    
    {
        r: Math.floor(153 /4),
        g: 0,
        b: Math.floor(51 /4)
    }
]

const segments = [
	{
		start: 0,
		len: 8
	},
	{
		start: 8,
		len: 6
	},
	{
		start: 14,
		len: 8
	},
	{
		start: 22,
		len: 6
	},


	{
		start: 28,
		len: 10
	},	
	{
		start: 38,
		len: 8
	},
	{
		start: 46,
		len: 10
	},	
	{
		start: 56,
		len: 6
	},
];

const firstHalfSegments = [
	{
		start: 0,
		len: 4
	},
	{
		start: 8,
		len: 3
	},
	{
		start: 14,
		len: 4
	},
	{
		start: 22,
		len: 3
	},


	{
		start: 28,
		len: 5
	},	
	{
		start: 38,
		len: 4
	},
	{
		start: 46,
		len: 5
	},	{
		start: 56,
		len: 3
	},
];
const lastHalfSegments = [
	{
		start: 4,
		len: 4
	},
	{
		start: 11,
		len: 3
	},
	{
		start: 18,
		len: 4
	},
	{
		start: 25,
		len: 3
	},


	{
		start: 33,
		len: 5
	},	
	{
		start: 42,
		len: 4
	},
	{
		start: 51,
		len: 5
	},	{
		start: 59,
		len: 3
	},
];

const glyphs = {
	// 0: [
	// 	segments[0], 
	// ],
	// 1: [
	// 	segments[1], 
	// ],
	// 2: [
	// 	segments[2], 
	// ],
	// 3: [
	// 	segments[3],
	// ],
	// 4: [
	// 	segments[4], 
	// ],
	// 5: [
	// 	segments[5], 
	// ],
	// 6: [
	// 	segments[6], 
	// ],
	// 7: [
	// 	segments[7], 
	// ],

	// 0: [
	// 	firstHalfSegments[0], 
	// ],
	// 1: [
	// 	firstHalfSegments[1], 
	// ],
	// 2: [
	// 	firstHalfSegments[2], 
	// ],
	// 3: [
	// 	firstHalfSegments[3],
	// ],
	// 4: [
	// 	firstHalfSegments[4], 
	// ],
	// 5: [
	// 	firstHalfSegments[5], 
	// ],
	// 6: [
	// 	firstHalfSegments[6], 
	// ],
	// 7: [
	// 	firstHalfSegments[7], 
	// ],

	// 0: [
	// 	lastHalfSegments[0], 
	// ],
	// 1: [
	// 	lastHalfSegments[1], 
	// ],
	// 2: [
	// 	lastHalfSegments[2], 
	// ],
	// 3: [
	// 	lastHalfSegments[3],
	// ],
	// 4: [
	// 	lastHalfSegments[4], 
	// ],
	// 5: [
	// 	lastHalfSegments[5], 
	// ],
	// 6: [
	// 	lastHalfSegments[6], 
	// ],
	// 7: [
	// 	lastHalfSegments[7], 
	// ],



	A: [
		segments[0], 
		segments[2], 
		segments[3], 
		segments[7]
	],
	// B: [
	// 	segments[0], 		
	// 	segments[1],
	// 	segments[3], 
	// 	lastHalfSegments[4],
	// 	firstHalfSegments[6],  
	// 	firstHalfSegments[7],  
	// ],
	B: [
		segments[1], 
		segments[2], 
		segments[3], 
		segments[5],  
		lastHalfSegments[7]
	],
	
	C: [
		segments[0],
		segments[1],
		segments[3],		
	],

	D: [
		segments[1], 
		segments[2],
		segments[3], 
		segments[5]
	],
	E: [
		segments[0],
		segments[1],
		segments[3],
		firstHalfSegments[7]		
	],
	F: [
		segments[0],
		segments[3],
		firstHalfSegments[7]
	],
	G: [
		segments[0],
		segments[1],
		firstHalfSegments[2],
		lastHalfSegments[7],
		segments[3]
	],
	H: [
		segments[0],
		segments[2],
		segments[7]
	],
	I: [
		segments[1],
		segments[3],
		segments[5],
	],
	J: [
		firstHalfSegments[1],
		segments[3],
		segments[5]
	],
	K: [
		// segments[5],
		// firstHalfSegments[6],
		// lastHalfSegments[4]
		segments[0],
		firstHalfSegments[6],
		firstHalfSegments[7],
		lastHalfSegments[4]
	],
	L: [
		segments[0],
		segments[1]
	],
	M: [
		segments[0],
		firstHalfSegments[4],
		firstHalfSegments[6],
		segments[2],
	],

	N: [
		segments[0],
		segments[2],
		segments[4]
	],
	O: [
		segments[0],
		segments[1],
		segments[2],
		segments[3],
	],
	P: [
		segments[0],
		lastHalfSegments[2],
		segments[3],
		segments[7]
	],
	Q: [
		segments[0],
		segments[1],
		segments[2],
		segments[3],
		lastHalfSegments[4]
	],
	R: [
		segments[0],
		lastHalfSegments[2],
		segments[3],
		lastHalfSegments[4],
		segments[7]
	],
	S: [
		firstHalfSegments[0],
		segments[1],
		firstHalfSegments[2],
		segments[3],
		segments[7]
	],
	T: [
		segments[3],
		segments[5]
		
	],
	U: [
		segments[0],
		segments[1],
		segments[2],
	],
	V: [
		segments[0],
		segments[6]
	],
	W: [
		segments[0],
		segments[2],
		lastHalfSegments[4],
		lastHalfSegments[6]
	],
	X: [
		segments[4],
		segments[6]
	],
	Y: [
		firstHalfSegments[4],
		firstHalfSegments[5],
		firstHalfSegments[6]
	],
	Z: [
		segments[1],
		segments[3],
		segments[6]
	],

	'': [],
	' ': []

}


// scheduleMessage
sendFrame = function(frame, txt, colors) {
	return () => {
		sendPix(
			getData(txt, colors) +
			'frame' + '=' + frame
		)};
}

doLedIndexToGlyphMask = function(ledIndex, glyph) {
	if (!glyph) { return false };
	for (let i=0, len=glyph.length; i<len; i++) {

		if (ledIndex >= glyph[i].start && 
			ledIndex < (glyph[i].start + glyph[i].len)) {
			return true;
		}
	}
	return false;
}

var getData = function(txt, colors) { 
	data = '';

	for (var j=0, len = txt.length; j<len; j++) {
		console.log(txt, len);
		let character = txt[j];
		let glyph = glyphs[character];

			for (var i=0; i<64; i++) {
				if (doLedIndexToGlyphMask(i, glyph)) {
					var r = colors.r << 16; //Math.floor(Math.random()*colors.r)<<16;
					var g = colors.g << 8; // Math.floor(Math.random()*colors.g)<<8;
					var b = colors.b ; //Math.floor(Math.random()*colors.b);

                    if (Math.random() < .15) {
                        r = 255 << 16
                        g = 255 << 8
                        b = 255;
                    }

                    data += ("p"+ "_" + j + "_" + i + '=' + '' + (r+g+b).toString(16) + '&')
				} else {
					var r = 0<<16;
					var g = 0<<8;
					var b = 0;
					data += ("p"+ "_" + j+"_"+i + '=' + '' + (r+g+b).toString(16) + '&')
				}
			}
		}
	// console.log(data);
	return data;
}

var sendPix =function(x) {
	console.log(x);
	return fetch('http://10.0.1.158/set?' + x);
}


let t = 1000;

// t += scheduleMessage('01234567 ');

let req;

// t += scheduleMessage('ABABABABABABABABABAB');
// for (var i=0; i<10; i++) {
// 	= scheduleMessage('FUCK ', colorSet[0], t);
// }

// let script = [
// 	{
// 		text: 'FUCK',
// 		colors: colorSet[0],
// 		count: 10
// 	},
// 	{
// 		text: 'MAB ',
// 		colors: colorSet[1],
// 		count: 10
// 	},
// 	{
// 		text: '    ',
// 		colors: colorSet[0],
// 		count: 10
// 	},
// 	{
// 		text: 'BLM ',
// 		colors: colorSet[2],
// 		count: 10
// 	},
// 	{
// 		text: 'BLM',
// 		colors: colorSet[1],
// 		count: 10
// 	}
// ]

let script = [];

var lineCount = 0

let addToScript = (text, colorSetIndex) => 
{
    for (var q=0; q<4; q++) {
		script.push({
			text: text,
			colors: colorSet[colorSetIndex]
		})
    }
    
    lineCount++
}

addToScript("FUCK", 3)
addToScript("THIS", 3)
addToScript("SHIT", 3)
addToScript("    ")

addToScript("FUCK", 4)
addToScript("THIS", 4)
addToScript("SHIT", 4)
addToScript("    ")

addToScript("FUCK", 5)
addToScript("THIS", 5)
addToScript("SHIT", 5)
addToScript("    ")
// addToSparkleScript("D   ", 1)
// addToSparkleScript(" D  ", 1)
// addToSparkleScript("  D ", 1)
// addToSparkleScript("   D", 1)
// addToSparkleScript("DDDD", 2)
// addToSparkleScript("FUND", 2)
// addToSparkleScript("COPS ", 2)
// addToSparkleScript("    ")




const errHandler = (e)=>{
	console.log('e??!', e);
}

let firstPromise = Promise.resolve(true);
let chain = firstPromise;

for (var i=0, len=script.length; i<len; i++) {
	var item = script[i];
	chain = chain.then(
		sendFrame(i, item.text, item.colors),
		errHandler
	)
}

// scheduleMessage('FUCK ', colorSet[0])
// .then(()=>{ scheduleMessage('FUCK ', colorSet[0]) })


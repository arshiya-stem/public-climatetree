function decodeUplink(input) {
  const bytes = input.bytes;

  // Validate length
  if (bytes.length < 9) {
    return {
      data: {},
      warnings: [],
      errors: ["Payload too short"]
    };
  }

  // Read Big Endian 16-bit values, starting at byte index 1 (skip header)
  function readUInt16BE(i) {
    return (bytes[i] << 8) | bytes[i + 1];
  }

  return {
    data: {
      DATA_1: readUInt16BE(1), // bytes 1–2
      DATA_2:  readUInt16BE(3), // bytes 3–4
      DATA_3:     readUInt16BE(5), // bytes 5–6
      DATA_4:           readUInt16BE(7)  // bytes 7–8
    },
    warnings: [],
    errors: []
  };
}

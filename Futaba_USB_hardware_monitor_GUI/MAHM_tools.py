HEADER_FORMAT = '<4siiiiiii'
ENTRY_FORMAT = '<260s260s260s260s260sfffiii'


class MAHM_shared_memory_header:
    def __init__(self, signature, version, headerSize, entryCount, entrySize, time, GPUentryCount, GPUentrySize):
        self.signature = signature.decode('cp1251')
        self.version = int(version)
        self.headerSize = int(headerSize)
        self.entryCount = int(entryCount)
        self.entrySize = int(entrySize)
        self.time = int(time)
        self.GPUentryCount = int(GPUentryCount)
        self.GPUentrySize = int(GPUentrySize)


class MAHM_shared_memory_entry:
    def __init__(self, name, units, localName, localUnits, format, data, minLimit, maxLimit, flags, Gpu, SrcId):
        self.name = name.decode('cp1251').strip(chr(0))
        self.units = units.decode('cp1251').strip(chr(0))
        self.localName = localName.decode('cp1251').strip(chr(0))
        self.localUnits = localUnits.decode('cp1251').strip(chr(0))
        self.format = format.decode('cp1251').strip(chr(0))
        self.data = float(data)
        self.minLimit = float(minLimit)
        self.maxLimit = float(maxLimit)
        self.flags = int(flags)
        self.Gpu = int(Gpu)
        self.SrcId = int(SrcId)

    def __repr__(self):
        return self.name + ': ' + '{:.0f}'.format(self.data) + self.units

    def update_values(self, name, units, localName, localUnits, format, data, minLimit, maxLimit, flags, Gpu, SrcId):
        self.name = name.decode('cp1251').strip(chr(0))
        self.units = units.decode('cp1251').strip(chr(0))
        self.localName = localName.decode('cp1251').strip(chr(0))
        self.localUnits = localUnits.decode('cp1251').strip(chr(0))
        self.format = format.decode('cp1251').strip(chr(0))
        self.data = float(data)
        self.minLimit = float(minLimit)
        self.maxLimit = float(maxLimit)
        self.flags = int(flags)
        self.Gpu = int(Gpu)
        self.SrcId = int(SrcId)
        if self.data > 1000000:
            self.data = 0.0

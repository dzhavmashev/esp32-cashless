// Function : FUN_401619a0
// Address  : 0x401619a0
// Size     : 98 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_401619a0(void)

{
  char cVar1;
  uint local_30 [12];
  
  cVar1 = DAT_3ffc1a44;
  if (DAT_3ffc1a44 != '\0') {
    memw();
    local_30[0] = (uint)DAT_3ffc1a3c;
    if (DAT_3ffc1a3c != 0) {
      return '\0';
    }
    if (_DAT_3ffc1a40 != 0) {
      memw();
      (*_DAT_3ffc7a20)(_DAT_3ffca204,DAT_3ffca1e3,local_30);
      (**(code **)(_DAT_3ffc1a34 + 0xec))(0x3ffca27c);
      (**(code **)(_DAT_3ffc1a34 + 0xf8))(0x3ffca27c,local_30[0],0);
      return cVar1;
    }
  }
  return '\0';
}


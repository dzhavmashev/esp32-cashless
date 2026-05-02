// Function : FUN_401133a0
// Address  : 0x401133a0
// Size     : 212 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_401133a0(uint *param_1,int param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  if (param_1 != (uint *)0x0) goto LAB_401133b8;
  pcVar4 = &DAT_3f411618;
  uVar3 = 0x87;
  while( true ) {
    (*(code *)&SUB_40094c54)("lid pcb",uVar3,"_if_src",pcVar4);
LAB_401133b8:
    if (param_2 != 0) break;
    pcVar4 = "e/udp.c";
    uVar3 = 0x88;
  }
  if (((char)param_1[0xc] == '\0') ||
     ((char)param_1[0xc] == (char)(*(char *)(_DAT_3ffc83bc + 0xee) + '\x01'))) {
    if ((char)param_1[5] != '.') {
      if (DAT_3ffc83f8 != (char)param_1[5]) goto LAB_4011346c;
      uVar2 = *param_1;
      if (param_3 != 0) {
        if (uVar2 == 0) {
          return true;
        }
        if (_DAT_3ffc83e4 == 0xffffffff) {
          return true;
        }
        return ((_DAT_3ffc83e4 ^ uVar2) & *(uint *)(param_2 + 0x1c)) == 0;
      }
      if (DAT_3ffc83f8 != '\x06') {
        if (uVar2 == 0) {
          return true;
        }
        return _DAT_3ffc83e4 == uVar2;
      }
      if ((((uVar2 != 0) || (param_1[1] != 0)) || (param_1[2] != 0)) || (param_1[3] != 0)) {
        if (_DAT_3ffc83e4 != uVar2) {
          return false;
        }
        if (param_1[1] != _DAT_3ffc83e8) {
          return false;
        }
        if (param_1[2] != _DAT_3ffc83ec) {
          return false;
        }
        if (param_1[3] != _DAT_3ffc83f0) {
          return false;
        }
        return (char)param_1[4] == DAT_3ffc83f4;
      }
    }
    bVar1 = true;
  }
  else {
LAB_4011346c:
    bVar1 = false;
  }
  return bVar1;
}


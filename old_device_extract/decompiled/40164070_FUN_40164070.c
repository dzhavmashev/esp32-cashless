// Function : FUN_40164070
// Address  : 0x40164070
// Size     : 102 bytes


undefined4 FUN_40164070(byte param_1)

{
  undefined4 uVar1;
  byte bVar2;
  
  uVar1 = 4;
  if (param_1 != 0x4e) {
    if (param_1 < 0x4f) {
      if (param_1 == 0x1a) {
        return 7;
      }
      if (param_1 < 0x1b) {
        uVar1 = 8;
        bVar2 = 0xd;
      }
      else {
        if (param_1 == 0x27) {
          return 6;
        }
        uVar1 = 5;
        bVar2 = 0x34;
      }
    }
    else {
      if (param_1 == 0x75) {
        return 2;
      }
      if (param_1 < 0x76) {
        uVar1 = 3;
        bVar2 = 0x68;
      }
      else {
        if (param_1 == 0x82) {
          return 1;
        }
        uVar1 = 0;
        bVar2 = 0x90;
      }
    }
    if (param_1 != bVar2) {
      FUN_40147fe4(6,0x200,1,"rate=%d");
      uVar1 = 0;
    }
  }
  return uVar1;
}


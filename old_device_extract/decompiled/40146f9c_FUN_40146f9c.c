// Function : FUN_40146f9c
// Address  : 0x40146f9c
// Size     : 111 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40146f9c(uint param_1,uint param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  iVar1 = FUN_401460c8();
  uVar5 = 0x3001;
  if ((iVar1 != 0) && (uVar5 = 0x3004, param_1 < 2)) {
    uVar4 = param_2 & 0xf7;
    if (uVar4 == 7) {
      uVar3 = 3;
    }
    else if (uVar4 == 3) {
      uVar3 = 2;
    }
    else {
      uVar3 = 1;
      if (uVar4 != 1) {
        if ((param_2 & 0xff) != 8) {
          return 0x102;
        }
        uVar3 = 4;
      }
    }
    puVar2 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x178))(0x18);
    uVar5 = 0x101;
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 0xc;
      memw();
      puVar2[8] = (char)param_1;
      *(undefined **)(puVar2 + 4) = &DAT_4014ff40;
      puVar2[9] = uVar3;
      puVar2[10] = (byte)((param_2 & 0xff) >> 3) & 1;
      memw();
      memw();
      uVar5 = FUN_40150444();
    }
  }
  return uVar5;
}


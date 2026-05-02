// Function : FUN_40146f58
// Address  : 0x40146f58
// Size     : 64 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40146f58(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  iVar1 = FUN_401460c8();
  uVar2 = 0x3001;
  if ((iVar1 != 0) && (uVar2 = 0x102, param_1 < 3)) {
    puVar3 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x178))(0x18);
    uVar2 = 0;
    if (puVar3 != (undefined1 *)0x0) {
      *(undefined4 *)(puVar3 + 4) = 0x40150030;
      *puVar3 = 0x13;
      puVar3[8] = (char)param_1;
      memw();
      memw();
      FUN_40150444();
      uVar2 = 0;
    }
  }
  return uVar2;
}


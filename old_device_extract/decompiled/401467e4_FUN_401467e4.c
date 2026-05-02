// Function : FUN_401467e4
// Address  : 0x401467e4
// Size     : 60 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401467e4(undefined1 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_401460c8();
  uVar3 = 0x3001;
  if (iVar1 != 0) {
    puVar2 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x178))(0x18);
    uVar3 = 0x101;
    if (puVar2 != (undefined1 *)0x0) {
      *(undefined1 **)(puVar2 + 4) = &LAB_4014eec8;
      *puVar2 = 10;
      puVar2[8] = param_1;
      memw();
      memw();
      uVar3 = FUN_40150444();
    }
  }
  return uVar3;
}


// Function : FUN_401475b8
// Address  : 0x401475b8
// Size     : 86 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401475b8(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_401460c8();
  uVar3 = 0x3001;
  if ((iVar1 != 0) && (uVar3 = 0x3002, 1 < DAT_3ffc89d9)) {
    puVar2 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x178))(0x18);
    uVar3 = 0x101;
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 0x34;
      memw();
      *(undefined4 *)(puVar2 + 4) = 0x40150350;
      puVar2[9] = 0;
      puVar2[10] = 0;
      puVar2[8] = param_2;
      memw();
      *(undefined4 *)(puVar2 + 0xc) = param_1;
      memw();
      uVar3 = FUN_40150444();
    }
  }
  return uVar3;
}


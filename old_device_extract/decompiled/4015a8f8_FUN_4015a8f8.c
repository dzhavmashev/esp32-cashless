// Function : FUN_4015a8f8
// Address  : 0x4015a8f8
// Size     : 82 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015a8f8(undefined1 param_1,undefined4 param_2,uint param_3,undefined1 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  iVar1 = FUN_401460c8();
  uVar2 = 0x3001;
  if (iVar1 != 0) {
    puVar3 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x178))(0x18);
    uVar2 = 0x101;
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 0x2e;
      memw();
      *(undefined4 *)(puVar3 + 4) = 0x401502bc;
      puVar3[10] = 0;
      puVar3[8] = param_1;
      puVar3[9] = param_4;
      memw();
      *(uint *)(puVar3 + 0xc) = param_3 & 0xffff;
      *(undefined4 *)(puVar3 + 0x14) = param_2;
      memw();
      uVar2 = FUN_40150444();
    }
  }
  return uVar2;
}


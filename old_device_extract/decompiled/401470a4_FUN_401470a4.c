// Function : FUN_401470a4
// Address  : 0x401470a4
// Size     : 82 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401470a4(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_401460c8();
  uVar3 = 0x3001;
  if ((iVar1 != 0) && (uVar3 = 0x102, param_1 != 0)) {
    puVar2 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x178))(0x18);
    uVar3 = 0x101;
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 8;
      memw();
      *(undefined ***)(puVar2 + 4) = &PTR_s_d_4014f948;
      puVar2[8] = 0;
      puVar2[9] = 0;
      puVar2[10] = 0;
      memw();
      *(undefined4 *)(puVar2 + 0xc) = 0;
      *(int *)(puVar2 + 0x14) = param_1;
      memw();
      uVar3 = FUN_40150444();
    }
  }
  return uVar3;
}


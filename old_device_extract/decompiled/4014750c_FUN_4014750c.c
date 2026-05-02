// Function : FUN_4014750c
// Address  : 0x4014750c
// Size     : 80 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4014750c(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  uVar3 = 0x102;
  if (param_2 != 0) {
    iVar1 = FUN_401460c8();
    uVar3 = 0x3001;
    if (iVar1 != 0) {
      puVar2 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x178))(0x18);
      uVar3 = 0x101;
      if (puVar2 != (undefined1 *)0x0) {
        *puVar2 = 0x30;
        memw();
        *(undefined ***)(puVar2 + 4) = &PTR_s_cmd__d_401502e4;
        puVar2[8] = 0;
        puVar2[9] = 0;
        puVar2[10] = 0;
        memw();
        *(undefined4 *)(puVar2 + 0xc) = param_1;
        *(int *)(puVar2 + 0x14) = param_2;
        memw();
        uVar3 = FUN_40150444();
      }
    }
  }
  return uVar3;
}


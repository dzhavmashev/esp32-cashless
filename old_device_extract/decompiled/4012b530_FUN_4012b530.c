// Function : FUN_4012b530
// Address  : 0x4012b530
// Size     : 57 bytes


undefined4 FUN_4012b530(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = (undefined4 *)FUN_4013ae30(1,0xc);
  uVar2 = 0xffff8100;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = 0;
    iVar3 = *param_1;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    if (iVar3 == 0) {
      *param_1 = (int)puVar1;
      uVar2 = 0;
    }
    else {
      do {
        iVar4 = iVar3;
        iVar3 = *(int *)(iVar4 + 8);
      } while (iVar3 != 0);
      *(undefined4 **)(iVar4 + 8) = puVar1;
      memw();
      uVar2 = 0;
    }
  }
  memw();
  return uVar2;
}


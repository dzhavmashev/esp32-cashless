// Function : FUN_4014170c
// Address  : 0x4014170c
// Size     : 43 bytes


undefined4 FUN_4014170c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar2 = *(undefined4 **)(param_1 + 4);
  puVar1 = puVar2;
  if (puVar2[2] != 0) {
    puVar1 = (undefined4 *)FUN_4013ae30(1,0x10);
    puVar2[3] = puVar1;
    uVar3 = 0xffffff96;
    if (puVar1 == (undefined4 *)0x0) goto LAB_40141730;
  }
  puVar1[2] = param_3;
  puVar1[1] = param_4;
  *puVar1 = param_2;
  *(undefined4 **)(param_1 + 4) = puVar1;
  uVar3 = 0;
LAB_40141730:
  memw();
  return uVar3;
}


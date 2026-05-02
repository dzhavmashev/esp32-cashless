// Function : FUN_40124580
// Address  : 0x40124580
// Size     : 97 bytes


void FUN_40124580(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  *(byte *)(param_1 + 0x67) = *(byte *)(param_1 + 0x67) | 1;
  memw();
  param_1[4] = 4;
  iVar1 = param_1[1];
  if (*(int *)(iVar1 + 0xcc) == 0) {
    uVar2 = *param_1;
    *(undefined4 *)(iVar1 + 0xcc) = 1;
    *(undefined4 *)(iVar1 + 0xd0) = 0;
    memw();
    FUN_401240c8(uVar2,iVar1);
    FUN_401241c4(uVar2,iVar1);
    FUN_40124248(uVar2,iVar1);
  }
  iVar1 = FUN_40102858(param_1 + 0x13,0x20);
  if (iVar1 == 0) {
    param_1[9] = 0;
    param_1[0xb] = 0;
    memw();
  }
  else {
    FUN_4015a5bc(param_1 + 2,0xf);
  }
  return;
}


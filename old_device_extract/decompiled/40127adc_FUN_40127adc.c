// Function : FUN_40127adc
// Address  : 0x40127adc
// Size     : 96 bytes


undefined4
FUN_40127adc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
            )

{
  int iVar1;
  undefined4 uVar2;
  
  if (((*(int *)(param_5 + 0x48) == 0) ||
      ((*(int *)(*(int *)(param_5 + 0x48) + 0x40) != 0 &&
       (iVar1 = FUN_40126bc0(param_5,param_1,param_2,param_3,param_4), iVar1 < 0)))) ||
     ((*(int *)(*(int *)(param_5 + 0x48) + 0x48) != 0 &&
      (iVar1 = FUN_401268fc(param_5,param_1,param_2,param_3,param_4), iVar1 < 0)))) {
    uVar2 = 0xffffffff;
  }
  else {
    *(byte *)(param_5 + 0x50) = *(byte *)(param_5 + 0x50) & 0xfe;
    memw();
    memw();
    uVar2 = FUN_40127038(param_5);
  }
  return uVar2;
}


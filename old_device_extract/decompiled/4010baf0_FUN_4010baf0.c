// Function : FUN_4010baf0
// Address  : 0x4010baf0
// Size     : 32 bytes


undefined4 FUN_4010baf0(undefined4 param_1,short param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = (int)param_2;
  if (iVar2 < 0) {
    uVar1 = FUN_4010ba9c(param_1,-iVar2);
  }
  else {
    uVar1 = FUN_4010b9c4(param_1,iVar2,1);
  }
  return uVar1;
}


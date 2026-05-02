// Function : FUN_400ebc28
// Address  : 0x400ebc28
// Size     : 80 bytes


bool FUN_400ebc28(int param_1,int param_2,char param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_3 != '\0') {
    uVar3 = FUN_400efe6c(0x3ffc53f4);
    uVar4 = FUN_400efe7c(0x3ffc53f4);
    if ((uVar3 < uVar4) * uVar4 + (uVar3 >= uVar4) * uVar3 < 0x4000) {
      return false;
    }
  }
  iVar1 = FUN_400ec5fc(param_2);
  iVar1 = param_2 + 1 + iVar1;
  *(int *)(param_1 + 8) = iVar1;
  iVar2 = func_0x40094d68(iVar1);
  *(int *)(param_1 + 4) = iVar2;
  if (iVar2 != 0) {
    func_0x4008b538(iVar2,0,iVar1);
  }
  else {
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return iVar2 != 0;
}


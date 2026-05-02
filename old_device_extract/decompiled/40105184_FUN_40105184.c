// Function : FUN_40105184
// Address  : 0x40105184
// Size     : 261 bytes


int FUN_40105184(char *param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (*param_1 == '\"') {
    param_1 = param_1 + 1;
    iVar1 = (*(code *)&SUB_4008ca2c)(param_1);
    if ((iVar1 != 0) && (*(char *)(iVar1 + 1) == '\0')) {
      *param_2 = iVar1 - (int)param_1;
      memw();
      iVar1 = FUN_40105150(param_1);
      return iVar1;
    }
  }
  else if ((*param_1 == 'P') && (param_1[1] == '\"')) {
    param_1 = param_1 + 2;
    iVar1 = (*(code *)&SUB_4008ca2c)(param_1);
    if ((iVar1 != 0) && (*(char *)(iVar1 + 1) == '\0')) {
      iVar2 = FUN_40105150(param_1,iVar1 - (int)param_1);
      if (iVar2 != 0) {
        iVar4 = (iVar1 - (int)param_1) + 1;
        iVar1 = (*(code *)&SUB_40094d60)(iVar4);
        if (iVar1 != 0) {
          uVar3 = FUN_4010501c(iVar1,iVar4,iVar2);
          *param_2 = uVar3;
          memw();
        }
        (*(code *)&SUB_40094d80)(iVar2);
        return iVar1;
      }
    }
  }
  else {
    uVar3 = (*(code *)&SUB_4008c01c)(param_1);
    if ((uVar3 & 0xfffffff7) == 5) {
      *param_2 = uVar3;
      memw();
      iVar1 = (*(code *)&SUB_40094d60)(uVar3 + 1);
      if (iVar1 == 0) {
        return 0;
      }
      (*(code *)&SUB_4008b3d0)(iVar1,param_1,uVar3);
      *(undefined1 *)(iVar1 + uVar3) = 0;
      memw();
      memw();
      return iVar1;
    }
    uVar3 = uVar3 >> 1;
    iVar1 = (*(code *)&SUB_40094d60)(uVar3 + 1);
    if (iVar1 != 0) {
      iVar2 = FUN_40104f84(param_1,iVar1,uVar3);
      if (iVar2 == 0) {
        *(undefined1 *)(iVar1 + uVar3) = 0;
        memw();
        *param_2 = uVar3;
        memw();
        return iVar1;
      }
      (*(code *)&SUB_40094d80)(iVar1);
    }
  }
  return 0;
}


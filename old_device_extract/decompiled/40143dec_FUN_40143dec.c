// Function : FUN_40143dec
// Address  : 0x40143dec
// Size     : 181 bytes


undefined4 FUN_40143dec(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  do {
    if (param_1 == (int *)0x0 && param_2 == (int *)0x0) {
      return 0;
    }
    if ((((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) || (*param_1 != *param_2)) ||
       ((param_1[1] != param_2[1] ||
        (iVar1 = (*(code *)&SUB_4008b33c)(param_1[2],param_2[2]), iVar1 != 0)))) {
      return 0xffffffff;
    }
    iVar3 = param_1[3];
    iVar1 = param_2[3];
    if (((iVar3 != iVar1) || (param_1[4] != param_2[4])) ||
       (iVar2 = (*(code *)&SUB_4008b33c)(param_1[5],param_2[5]), iVar2 != 0)) {
      if ((iVar3 != 0xc) && (iVar3 != 0x13)) {
        return 0xffffffff;
      }
      if ((iVar1 != 0xc) && (iVar1 != 0x13)) {
        return 0xffffffff;
      }
      if (param_1[4] != param_2[4]) {
        return 0xffffffff;
      }
      iVar1 = FUN_4018681c(param_1[5],param_2[5]);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
    }
    if ((char)param_1[7] != (char)param_2[7]) {
      return 0xffffffff;
    }
    param_1 = (int *)param_1[6];
    param_2 = (int *)param_2[6];
  } while( true );
}


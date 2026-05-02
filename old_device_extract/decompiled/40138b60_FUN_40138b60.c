// Function : FUN_40138b60
// Address  : 0x40138b60
// Size     : 136 bytes


void FUN_40138b60(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  
  if (param_3 != 0) {
    (*(code *)&SUB_4008b530)(param_2,0,param_3);
    if ((int)param_1 < 1) {
      param_1 = -param_1;
    }
    uVar4 = param_1 & 0xff80;
    if (uVar4 != 0) {
      uVar1 = FUN_40137ff4(param_1);
      pcVar5 = " length";
      uVar3 = uVar4;
      if (uVar1 != 0) {
        pcVar5 = "o %s";
        uVar3 = uVar1;
      }
      FUN_401742a8(param_2,param_3,pcVar5,uVar3);
      if (uVar4 == 0x7780) {
        return;
      }
    }
    if ((param_1 & 0xffff007f) != 0) {
      iVar2 = (*(code *)&SUB_4008c01c)(param_2);
      if (iVar2 != 0) {
        uVar4 = param_3 - iVar2;
        if (uVar4 < 5) {
          return;
        }
        FUN_401742a8(param_2 + iVar2,uVar4," (%04X)");
        param_2 = param_2 + iVar2 + 3;
        param_3 = uVar4 - 3;
      }
      uVar3 = FUN_40138908(param_1);
      pcVar5 = " length";
      uVar4 = param_1 & 0xffff007f;
      if (uVar3 != 0) {
        pcVar5 = "o %s";
        uVar4 = uVar3;
      }
      FUN_401742a8(param_2,param_3,pcVar5,uVar4);
    }
  }
  return;
}


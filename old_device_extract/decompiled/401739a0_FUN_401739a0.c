// Function : FUN_401739a0
// Address  : 0x401739a0
// Size     : 220 bytes


ulonglong FUN_401739a0(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  
  uVar5 = CONCAT44(param_2,param_1);
  uVar1 = param_2 >> 0x14 & 0x7ff;
  if (uVar1 == 0) {
    if ((param_2 & 0x7fffffff) == 0 && param_1 == 0) {
      return uVar5;
    }
    uVar5 = (*(code *)&SUB_4006358c)(param_1,param_2,0,0x43500000);
    uVar3 = 0xc2f8f359;
    uVar4 = 0x1a56e1f;
    if (param_3 < -50000) goto LAB_40173a7e;
    uVar1 = ((uint)(uVar5 >> 0x34) & 0x7ff) - 0x36;
  }
  else if (uVar1 == 0x7ff) {
    (*(code *)&SUB_40002590)(param_1,param_2,param_1,param_2);
    uVar5 = FUN_40173a84();
    return uVar5;
  }
  iVar2 = param_3 + uVar1;
  if (iVar2 < 0x7ff) {
    if (0 < iVar2) {
      uVar5 = FUN_40173a84(param_1,param_2,0x800fffff);
      return uVar5;
    }
    if (-0x36 < iVar2) {
      uVar3 = 0;
      uVar4 = 0x3c900000;
      uVar5 = CONCAT44((iVar2 + 0x36) * 0x100000 | (uint)(uVar5 >> 0x20) & 0x800fffff,(int)uVar5);
      goto LAB_40173a7e;
    }
    if (param_3 < 0xc351) {
      uVar3 = 0x1a56e1f;
      if ((uVar5 & 0x8000000000000000) != 0) {
        uVar3 = 0x81a56e1f;
      }
      uVar5 = CONCAT44(uVar3,0xc2f8f359);
      uVar3 = 0xc2f8f359;
      uVar4 = 0x1a56e1f;
      goto LAB_40173a7e;
    }
  }
  uVar3 = 0x7e37e43c;
  if ((uVar5 & 0x8000000000000000) != 0) {
    uVar3 = 0xfe37e43c;
  }
  uVar5 = CONCAT44(uVar3,0x8800759c);
  uVar3 = 0x8800759c;
  uVar4 = 0x7e37e43c;
LAB_40173a7e:
  uVar5 = (*(code *)&SUB_4006358c)((int)uVar5,(int)(uVar5 >> 0x20),uVar3,uVar4);
  return uVar5;
}


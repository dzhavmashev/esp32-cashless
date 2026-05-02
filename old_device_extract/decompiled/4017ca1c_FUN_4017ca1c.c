// Function : FUN_4017ca1c
// Address  : 0x4017ca1c
// Size     : 92 bytes


undefined8 FUN_4017ca1c(int param_1,uint param_2,int *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = CONCAT44(param_2,param_1);
  *param_3 = 0;
  uVar1 = param_2 & 0x7fffffff;
  if ((uVar1 < 0x7ff00000) && (uVar1 != 0 || param_1 != 0)) {
    if ((param_2 & 0x7ff00000) == 0) {
      uVar2 = (*(code *)&SUB_4006358c)(param_1,param_2,0,0x43500000);
      uVar1 = (uint)((ulonglong)uVar2 >> 0x20) & 0x7fffffff;
      *param_3 = -0x36;
    }
    param_1 = (int)uVar2;
    *param_3 = *param_3 + ((int)uVar1 >> 0x14) + -0x3fe;
    param_2 = (uint)((ulonglong)uVar2 >> 0x20) & 0x800fffff | 0x3fe00000;
  }
  return CONCAT44(param_2,param_1);
}


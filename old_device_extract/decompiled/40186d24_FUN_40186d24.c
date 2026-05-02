// Function : FUN_40186d24
// Address  : 0x40186d24
// Size     : 74 bytes


int FUN_40186d24(uint param_1,char param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = ((int)((param_4 & 0xffff) * (param_1 & 0xffff)) / param_3) * param_3;
  iVar2 = param_1 * 10 - (iVar1 * 10) / (int)param_4;
  if (iVar2 < param_2 * 10) {
    return -iVar2;
  }
  iVar1 = param_1 * -10 + ((param_3 + iVar1) * 10) / (int)param_4;
  if (param_2 * 10 <= iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}


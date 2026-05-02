// Function : FUN_4017c25c
// Address  : 0x4017c25c
// Size     : 151 bytes


int FUN_4017c25c(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  for (iVar3 = 1; iVar3 < (param_4 + 8) / 9; iVar3 = iVar3 << 1) {
    iVar4 = iVar4 + 1;
  }
  iVar3 = FUN_4017c100(param_1,iVar4);
  if (iVar3 == 0) {
    iVar3 = (*(code *)&SUB_40094c54)(&DAT_3f4260d0,0xce,0,"/dtoa.c");
  }
  *(undefined4 *)(iVar3 + 0x14) = param_5;
  *(undefined4 *)(iVar3 + 0x10) = 1;
  if (param_3 < 10) {
    pbVar2 = (byte *)(param_2 + 10);
    param_3 = 9;
    iVar4 = param_3;
  }
  else {
    pbVar2 = (byte *)(param_2 + 9);
    do {
      bVar1 = *pbVar2;
      pbVar2 = pbVar2 + 1;
      iVar3 = FUN_4017c1d4(param_1,iVar3,10,bVar1 - 0x30);
    } while (pbVar2 != (byte *)(param_2 + param_3));
    pbVar2 = (byte *)(param_2 + 9) + param_3 + -8;
    iVar4 = param_3;
  }
  for (; param_3 < param_4; param_3 = param_3 + 1) {
    iVar3 = FUN_4017c1d4(param_1,iVar3,10,pbVar2[param_3 - iVar4] - 0x30);
  }
  return iVar3;
}


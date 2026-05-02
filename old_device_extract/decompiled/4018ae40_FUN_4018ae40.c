// Function : FUN_4018ae40
// Address  : 0x4018ae40
// Size     : 78 bytes


int FUN_4018ae40(uint param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(&DAT_3ffc06e0 + (param_1 & 0xff) * 4);
  while( true ) {
    if (uVar4 == 0) {
      return 0;
    }
    uVar3 = 0x1f - LZCOUNT(-uVar4 & uVar4);
    iVar1 = *(int *)(&DAT_3ffc7d14 + uVar3 * 4);
    iVar2 = (*(code *)&SUB_4008b33c)(iVar1 + 0x1f,param_2,6);
    if (iVar2 == 0) break;
    uVar4 = uVar4 & (1 << 0x20 - (0x20 - (uVar3 & 0x1f)) ^ 0xffffffffU);
  }
  return iVar1;
}


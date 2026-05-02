// Function : FUN_400ec2a8
// Address  : 0x400ec2a8
// Size     : 96 bytes


undefined4 FUN_400ec2a8(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar2 = (uint)param_1[6] >> 8 & 0xffff;
  uVar4 = uVar2 | *(byte *)(*param_1 + param_1[2]);
  *(char *)((int)param_1 + 0x1a) = (char)(uVar2 >> 8);
  iVar1 = 0;
  *(char *)((int)param_1 + 0x19) = (char)uVar4;
  iVar3 = ((uint)*(byte *)(param_1 + 6) << 0x18 | (uint)param_1[5] >> 8) - 2;
  uVar5 = 2;
  if ((*(byte *)(param_1 + 5) & 6) != 0) {
    iVar1 = 2;
  }
  if ((uint)(iVar3 - iVar1) < uVar4) {
    param_1[4] = (int)&LAB_400ec520;
  }
  else {
    param_1[4] = (int)&LAB_400ec420;
    param_1[3] = 0;
    param_1[0x2b] = iVar3 - uVar4;
    uVar5 = 0;
  }
  return uVar5;
}


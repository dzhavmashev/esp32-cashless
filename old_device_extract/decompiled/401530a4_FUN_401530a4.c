// Function : FUN_401530a4
// Address  : 0x401530a4
// Size     : 155 bytes


undefined4 FUN_401530a4(int param_1)

{
  int *piVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined1 auStack_30 [48];
  
  if ((((((**(uint **)(param_1 + 0x2c) & 0x4000) == 0) && (*(ushort *)(param_1 + 0x16) + 8 < 0x60f))
       && (pbVar2 = *(byte **)(*(int *)(param_1 + 4) + 4),
          CONCAT11(pbVar2[0xc],pbVar2[0xd]) != -0x7772)) &&
      ((piVar1 = (int *)FUN_40152e4c((*(uint **)(param_1 + 0x2c))[4] >> 0x13 & 1,pbVar2,auStack_30),
       piVar1 != (int *)0x0 && (uVar4 = piVar1[3], (uVar4 & 0x80002) == 0x80002)))) &&
     ((*(int *)(*piVar1 + 0x14c) != 1 || ((*pbVar2 & 1) == 0)))) {
    iVar5 = *(int *)(param_1 + 0x2c);
    uVar3 = *(uint *)(iVar5 + 4);
    uVar6 = uVar3 & 0xf;
    if (uVar6 == 0xf) {
      uVar6 = FUN_40151f00(piVar1,param_1);
      *(uint *)(iVar5 + 4) = uVar3 & 0xfffffff0 | uVar6 & 0xf;
    }
    if (((uVar4 & 0x800) == 0) ||
       ((piVar1[uVar6 + 0x91] != 0 && ((*(ushort *)(piVar1[uVar6 + 0x91] + 0x2c) & 0x80) != 0)))) {
      memw();
      return 1;
    }
  }
  return 0;
}


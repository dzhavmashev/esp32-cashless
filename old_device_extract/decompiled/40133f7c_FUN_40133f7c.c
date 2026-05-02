// Function : FUN_40133f7c
// Address  : 0x40133f7c
// Size     : 85 bytes


int FUN_40133f7c(undefined4 param_1,int *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  ushort *puVar4;
  
  puVar3 = (ushort *)*param_2;
  if (1 < param_3 - (int)puVar3) {
    puVar4 = puVar3 + 1;
    uVar2 = (*puVar3 & 0xff) << 8 | (uint)(*puVar3 >> 8);
    *param_2 = (int)puVar4;
    if ((int)uVar2 <= param_3 - (int)puVar4) {
      memw();
      iVar1 = FUN_4013183c(param_1,puVar4,uVar2);
      if (iVar1 != 0) {
        return iVar1 + -0x3100;
      }
      *param_2 = *param_2 + uVar2;
      memw();
      return 0;
    }
  }
  return -0x3080;
}


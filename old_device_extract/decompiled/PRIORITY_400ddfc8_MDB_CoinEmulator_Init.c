// Function : MDB_CoinEmulator_Init
// Address  : 0x400ddfc8
// Size     : 200 bytes


void MDB_CoinEmulator_Init(int param_1,float param_2,int *param_3)

{
  ulonglong uVar1;
  bool bVar2;
  undefined *puVar3;
  float fVar4;
  int iVar5;
  char *pcVar6;
  undefined8 uVar7;
  short asStack_22 [17];
  
  if (*(char *)(param_1 + 0xa4) == '\0') {
    puVar3 = &DAT_3f401ace;
  }
  else {
    if (0.0 < param_2) {
      fVar4 = (float)FUN_40172a70(param_2);
      uVar1 = (ulonglong)(fVar4 * 1.0);
      bVar2 = uVar1 >> 0x10 != 0;
      asStack_22[0] =
           (ushort)((!NAN(fVar4) && !bVar2) && -1 < (longlong)uVar1) * (short)uVar1 -
           (ushort)(NAN(fVar4) || bVar2);
      pcVar6 = " %.2f)\n";
      if (*(int *)(param_1 + 0x9c) != 0) {
        iVar5 = func_0x4008fac0(*(int *)(param_1 + 0x9c),asStack_22,1000,0);
        if (iVar5 == 1) {
          (*(code *)&SUB_40002c34)(param_2);
          FUN_400f06a4(0x3ffc5490,"ilable\n","de: %d\n");
          if ((*(byte *)((int)param_3 + 0xf) & 0x80) == 0) {
            param_3 = (int *)*param_3;
          }
          func_0x4008c100(param_1 + 0xac,param_3,0x1f);
          *(undefined1 *)(param_1 + 0xcb) = 0;
          *(float *)(param_1 + 0xa8) = param_2;
          *(undefined1 *)(param_1 + 0xa5) = 1;
          return;
        }
        pcVar6 = "D: %s)\n";
      }
      FUN_400f06a4(0x3ffc5490,pcVar6,"de: %d\n");
      return;
    }
    puVar3 = &DAT_3f401ac9;
  }
  uVar7 = (*(code *)&SUB_40002c34)(param_2);
  FUN_400f06a4(0x3ffc5490,"CoinEmu","de: %d\n",puVar3,(int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
  return;
}


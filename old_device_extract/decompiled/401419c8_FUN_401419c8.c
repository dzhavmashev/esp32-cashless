// Function : FUN_401419c8
// Address  : 0x401419c8
// Size     : 140 bytes


int FUN_401419c8(uint *param_1,int param_2,uint *param_3,uint *param_4)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  int aiStack_24 [9];
  
  iVar1 = FUN_40141738(param_1,param_2,aiStack_24,0x30);
  if (iVar1 == 0) {
    pbVar3 = (byte *)*param_1;
    iVar1 = -0x60;
    if (0 < param_2 - (int)pbVar3) {
      pbVar2 = pbVar3 + aiStack_24[0];
      *param_3 = (uint)*pbVar3;
      memw();
      iVar1 = FUN_40141738(param_1,pbVar2,param_3 + 1,6);
      if (iVar1 == 0) {
        uVar4 = *param_1;
        param_3[2] = uVar4;
        pbVar3 = (byte *)(uVar4 + param_3[1]);
        *param_1 = (uint)pbVar3;
        if (pbVar3 == pbVar2) {
          memw();
          FUN_4013ae54(param_4,0xc);
        }
        else {
          *param_4 = (uint)*pbVar3;
          *param_1 = (uint)(pbVar3 + 1);
          memw();
          iVar1 = FUN_40186734(param_1,pbVar2,param_4 + 1);
          if (iVar1 == 0) {
            uVar4 = *param_1;
            param_4[2] = uVar4;
            pbVar3 = (byte *)(uVar4 + param_4[1]);
            *param_1 = (uint)pbVar3;
            if (pbVar3 != pbVar2) {
              iVar1 = -0x66;
            }
            memw();
          }
        }
      }
    }
  }
  return iVar1;
}


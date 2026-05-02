// Function : FUN_400eb880
// Address  : 0x400eb880
// Size     : 323 bytes


void FUN_400eb880(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  int aiStack_24 [9];
  
  iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0xc))(*(int **)(param_1 + 8),param_1 + 0xd8,0x5a0);
  if (0 < iVar1) {
    uVar2 = FUN_400f1a9c();
    iVar5 = 0;
    *(undefined4 *)(param_1 + 0x760) = uVar2;
    iVar6 = param_1 + 0xb0;
    do {
      aiStack_24[0] = 0;
      iVar3 = (*(code *)&LAB_4018453f_1)(param_1 + 0x68c,param_1 + iVar5 + 0xd8,iVar1,aiStack_24);
      if (iVar3 == 1) {
        pbVar4 = (byte *)FUN_40184578(param_1 + 0x68c);
        bVar7 = *pbVar4 & 0xf0;
        iVar3 = FUN_40184464(iVar6);
        if (iVar3 == 3) {
          if (bVar7 != 0x20) {
            (*(code *)&LAB_40184472_2)(iVar6,7);
            return;
          }
LAB_400eb914:
          FUN_400eb7d8(param_1);
          iVar3 = FUN_40184464(iVar6);
          if (iVar3 != 4) {
            return;
          }
        }
        else if (bVar7 == 0x60) {
          FUN_400eb6cc(param_1);
        }
        else if (bVar7 < 0x61) {
          if (bVar7 == 0x30) {
            iVar3 = FUN_40184464(iVar6);
            if (iVar3 < 5) {
              FUN_400eb540(param_1);
            }
          }
          else if (bVar7 < 0x31) {
            if (bVar7 == 0x20) goto LAB_400eb914;
          }
          else if (bVar7 == 0x40) {
            FUN_400eae1c(param_1);
          }
          else if (bVar7 == 0x50) {
            FUN_400eb668(param_1);
          }
        }
        else if (bVar7 == 0x90) {
          FUN_400eaf18(param_1);
        }
        else if (bVar7 < 0x91) {
          if (bVar7 == 0x70) {
            FUN_400eae98(param_1);
          }
        }
        else if (bVar7 == 0xb0) {
          FUN_400eafc8(param_1);
        }
        else if (bVar7 == 0xd0) {
          *(undefined1 *)(param_1 + 0x764) = 0;
        }
      }
      else if (iVar3 == 2) {
        (*(code *)&LAB_40184472_2)(param_1 + 0xb0,7);
        *(undefined1 *)(param_1 + 0x765) = 7;
        return;
      }
      iVar1 = iVar1 - aiStack_24[0];
      iVar5 = iVar5 + aiStack_24[0];
    } while (0 < iVar1);
  }
  return;
}


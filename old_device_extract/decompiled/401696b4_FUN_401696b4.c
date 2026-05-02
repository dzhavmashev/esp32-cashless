// Function : FUN_401696b4
// Address  : 0x401696b4
// Size     : 936 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401696b4(uint param_1,uint param_2,uint param_3,byte *param_4,int param_5,int param_6,
                 int param_7,byte param_8)

{
  int iVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  code *pcVar7;
  byte *pbVar8;
  ushort *puVar9;
  undefined1 auStack_90 [16];
  undefined1 auStack_80 [12];
  ushort local_74 [5];
  short sStack_6a;
  short sStack_68;
  uint uStack_60;
  byte *pbStack_5c;
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  uint uStack_4c;
  byte *pbStack_48;
  int iStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  int iStack_30;
  uint uStack_2c;
  byte *pbStack_28;
  
  uStack_60 = param_1 & 0xff;
  param_2 = param_2 & 0xff;
  uStack_2c = (uint)param_8;
  sStack_6a = _DAT_3ffc32dc;
  sStack_68 = _DAT_3ffc32de;
  memw();
  pbStack_48 = param_4;
  iStack_44 = param_6;
  uStack_38 = param_3 & 0xff;
  iStack_30 = param_5;
  (*(code *)&SUB_4008b3d0)(local_74,0x3ffc32bc,10);
  (**(code **)(_DAT_3ffc7e64 + 0x40))(1);
  (**(code **)(_DAT_3ffc7e64 + 0x3c))(1);
  FUN_4016f9ec(0xe);
  if (param_2 < (param_3 & 0xff)) {
    uStack_34 = 9;
    if (uStack_60 != 0) {
      uStack_34 = 0;
    }
    pbStack_28 = pbStack_48 + (uStack_2c - 1);
    do {
      iVar1 = iStack_30;
      if (param_2 == 1) {
        (**(code **)(_DAT_3ffc7e64 + 0xb8))(2,1,*(undefined2 *)(iStack_30 + 0x2a));
        (**(code **)(_DAT_3ffc7e64 + 0xb8))(3,1,*(undefined2 *)(iVar1 + 0x28));
        uStack_50 = 4;
LAB_40169776:
        uStack_4c = 1;
        sStack_6a = 0x100;
        sStack_68 = 0x100;
        memw();
      }
      else {
        if (param_2 == 0) {
          (**(code **)(_DAT_3ffc7e64 + 0xb8))(2,2,0x100);
          (**(code **)(_DAT_3ffc7e64 + 0xb8))(3,2,0x100);
          uStack_50 = uStack_2c;
          goto LAB_40169776;
        }
        if (param_2 == 2) {
          (**(code **)(_DAT_3ffc7e64 + 0xb8))(2,2,*(undefined2 *)(iStack_44 + 6));
          (**(code **)(_DAT_3ffc7e64 + 0xb8))(3,2,*(uint *)(iStack_44 + 4) & 0x1ff);
          uStack_4c = 0xe;
        }
        else {
          (**(code **)(_DAT_3ffc7e64 + 0xb8))(2,2,*(undefined2 *)(iStack_44 + 6));
          (**(code **)(_DAT_3ffc7e64 + 0xb8))(3,2,*(uint *)(iStack_44 + 4) & 0x1ff);
          uStack_4c = 1;
        }
        uStack_50 = 1;
        sStack_6a = (short)((uint)*(undefined4 *)(iStack_30 + 0x28) >> 0x10);
        sStack_68 = (short)*(undefined4 *)(iStack_30 + 0x28);
        memw();
      }
      uVar4 = 0;
      uStack_58 = 1;
      uStack_40 = uStack_34;
      uStack_3c = 0;
      pbStack_5c = pbStack_48 + (uStack_50 - 1 & 0xff) + 1;
      do {
        if (param_2 == 2) {
          uVar6 = uStack_58 & 0xff;
          FUN_4016f9ec(uStack_58);
          uStack_54 = uVar6;
        }
        else {
          uStack_54 = uStack_58 & 0xff;
        }
        if (uStack_60 != 0) {
          pcVar7 = *(code **)(_DAT_3ffc7e64 + 0xa0);
          uVar5 = FUN_4016e670(4);
          (*pcVar7)(100,0,4,uVar5);
          pcVar7 = *(code **)(_DAT_3ffc7e64 + 0xa0);
          uVar5 = FUN_4016e670(7);
          (*pcVar7)(100,0,7,uVar5);
        }
        if (uStack_50 != 0) {
          puVar9 = local_74;
          pbVar8 = pbStack_48;
          do {
            if (param_2 == 1) {
              bVar2 = pbStack_48[1];
              uVar3 = *puVar9;
              (**(code **)(_DAT_3ffc7e64 + 0xb8))(0,1);
              (**(code **)(_DAT_3ffc7e64 + 200))((uint)bVar2 << 8 | (uVar3 & 0x1fff) << 3);
              FUN_4016c698(uStack_60,1,0x800,&sStack_6a,auStack_80,auStack_90 + uVar4);
              iVar1 = uStack_3c * 4;
              uStack_3c = uStack_3c + 1 & 0xff;
              *(int *)(iVar1 + iStack_44) = (int)sStack_6a << 0x10 | (int)sStack_68;
            }
            else {
              if (param_2 == 2) {
                bVar2 = *pbStack_28;
                (**(code **)(_DAT_3ffc7e64 + 0xb8))(0,1,0x184);
                (**(code **)(_DAT_3ffc7e64 + 200))((uint)bVar2 << 8);
                (**(code **)(_DAT_3ffc7e64 + 0xb8))(2,2,*(undefined2 *)(iStack_44 + 6));
                (**(code **)(_DAT_3ffc7e64 + 0xb8))(3,2,*(uint *)(iStack_44 + 4) & 0x1ff);
                FUN_4016c698(uStack_60,2,0x800,&sStack_6a,auStack_80,auStack_90 + uVar4);
              }
              else {
                bVar2 = *pbVar8;
                (**(code **)(_DAT_3ffc7e64 + 0xb8))(0,1,0x184);
                (**(code **)(_DAT_3ffc7e64 + 200))((uint)bVar2 << 8);
                FUN_4016c698(uStack_60,param_2,0x800,&sStack_6a,auStack_80,auStack_90 + uVar4);
                if (param_2 == 0) {
                  iVar1 = uStack_40 * 4;
                  uStack_40 = uStack_40 + 1 & 0xff;
                  *(int *)(iVar1 + iStack_30) = (int)sStack_6a << 0x10 | (int)sStack_68;
                  goto LAB_4016997e;
                }
              }
              iVar1 = uVar4 * 4;
              uVar4 = uVar4 + 1 & 0xff;
              *(int *)(iVar1 + param_7) = (int)sStack_6a << 0x10 | (int)sStack_68;
            }
LAB_4016997e:
            pbVar8 = pbVar8 + 1;
            puVar9 = puVar9 + 1;
          } while (pbStack_5c != pbVar8);
        }
        uStack_58 = uStack_58 + 1;
      } while (uStack_54 < uStack_4c);
      param_2 = param_2 + 1 & 0xff;
    } while (param_2 < uStack_38);
  }
  if (uStack_60 == 0) {
    FUN_401694ec(param_7,auStack_90);
  }
  else {
    FUN_4016f9ec(0xe);
  }
  (**(code **)(_DAT_3ffc7e64 + 0x40))(0);
  (**(code **)(_DAT_3ffc7e64 + 0x3c))(0);
  return;
}


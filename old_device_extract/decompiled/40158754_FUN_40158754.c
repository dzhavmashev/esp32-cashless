// Function : FUN_40158754
// Address  : 0x40158754
// Size     : 524 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40158754(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined1 uVar8;
  undefined1 auStack_40 [16];
  int iStack_30;
  int iStack_2c;
  undefined1 *puStack_28;
  
  iVar2 = _DAT_3ffc8804;
  pcVar3 = (char *)(uint)*(byte *)(_DAT_3ffc8800 + 0x156);
  iStack_30 = _DAT_3ffc8800;
  if ((byte)(*(char *)(param_2 + 3) - 1U) < 0xe) {
    puVar4 = &DAT_3ffc87f0;
    if (_DAT_3ffc8864 == 0) {
      puStack_28 = &DAT_3ffc87f0;
      memw();
      iStack_2c = param_1;
      FUN_40147fe4(1,0x8000,3,0x3f435148,*(char *)(param_2 + 3),pcVar3);
      param_1 = iStack_2c;
      puVar4 = puStack_28;
    }
    if (puVar4[0x1e7] == '\x01') {
      if (*(int *)(puVar4 + 0x74) == 0) {
        return 0xffffffff;
      }
      if (param_1 != 0) {
        return 0xffffffff;
      }
      pcVar6 = pcVar3;
      if (iVar2 != 0) {
        pcVar6 = (char *)(uint)*(byte *)(iVar2 + 0x156);
      }
      uVar8 = *(undefined1 *)(param_2 + 4);
      uVar5 = 0x3f4350f7;
      memw();
      pcVar7 = (char *)(uint)(byte)puVar4[0x1e4];
      pcVar3 = (char *)(uint)*(byte *)(param_2 + 3);
    }
    else if (pcVar3 == (char *)(uint)*(byte *)(param_2 + 3)) {
      if (*(int *)(puVar4 + 0x74) == 0) {
        return 0xffffffff;
      }
      uVar8 = *(undefined1 *)(param_2 + 4);
      pcVar6 = " beacon";
      if (param_1 != 0) {
        pcVar6 = "_scan.c";
      }
      uVar5 = 0x3f4350bb;
      pcVar7 = pcVar3;
    }
    else {
      if (((*(int *)(puVar4 + 0x74) == 0) || (iVar2 == 0)) ||
         (pcVar7 = (char *)(uint)*(byte *)(iVar2 + 0x156),
         pcVar7 != (char *)(uint)*(byte *)(param_2 + 3))) {
        puVar4[0x1e7] = 1;
        memw();
        bVar1 = *(byte *)(param_2 + 4);
        puVar4[0x1e8] = bVar1;
        memw();
        puVar4[0x1e4] = *(undefined1 *)(param_2 + 3);
        puVar4[0x1e5] = 0;
        memw();
        if (((*_DAT_3ffbfc54 == '\x03') && (puVar4[0x1e6] != '\0')) && (bVar1 < 3)) {
          puVar4[0x1e8] = 3;
          memw();
        }
        memw();
        iStack_2c = param_1;
        puStack_28 = puVar4;
        FUN_40147fe4(1,4,4,0x3f433cff,*(undefined1 *)(param_2 + 3),pcVar3,(byte)puVar4[0x1e8] + 1);
        (**(code **)(_DAT_3ffc1a34 + 0xec))(0x3ffc7a74);
        (**(code **)(_DAT_3ffc1a34 + 0xf0))(0x3ffc7a74);
        (**(code **)(_DAT_3ffc1a34 + 0xf4))(0x3ffc7a74,0x4015b8f8,0);
        if (*(int *)(puStack_28 + 0x74) == 0) {
          memw();
          iStack_2c = *(int *)(puStack_28 + 0x74);
          (**(code **)(_DAT_3ffc1a34 + 0xe8))
                    (0x3ffc7a74,
                     ((byte)puVar4[0x1e8] + 1) *
                     (uint)*(ushort *)(*(int *)(iStack_30 + 0xe4) + 0x28),0);
        }
        else {
          pcVar7 = " beacon";
          if (iStack_2c != 0) {
            pcVar7 = "_scan.c";
          }
          if (iVar2 != 0) {
            pcVar3 = (char *)(uint)*(byte *)(iVar2 + 0x156);
          }
          puStack_28 = (undefined1 *)0x3ffc7a74;
          memw();
          FUN_40147fe4(1,0x8000,3,0x3f43504e,pcVar7,*(undefined1 *)(param_2 + 3),pcVar3,
                       *(undefined1 *)(param_2 + 4));
          auStack_40[0] = puVar4[0x1e4];
          memw();
          memw();
          FUN_40147270(0x23,auStack_40,1);
          (**(code **)(_DAT_3ffc1a34 + 0xe8))
                    (puStack_28,((byte)puVar4[0x1e8] + 1) * (uint)*(ushort *)(_DAT_3ffbfc54 + 0x3f8)
                     ,0);
        }
        return 0;
      }
      uVar8 = *(undefined1 *)(param_2 + 4);
      pcVar6 = " beacon";
      if (param_1 != 0) {
        pcVar6 = "_scan.c";
      }
      uVar5 = 0x3f43507f;
      memw();
      pcVar3 = pcVar7;
    }
    memw();
    FUN_40147fe4(1,0x8000,3,uVar5,pcVar6,pcVar7,pcVar3,uVar8);
  }
  else {
    memw();
    FUN_40147fe4(1,0x8000,2,0x3f436cad);
  }
  return 0xffffffff;
}


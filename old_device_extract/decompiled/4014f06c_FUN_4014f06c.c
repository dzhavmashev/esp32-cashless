// Function : FUN_4014f06c
// Address  : 0x4014f06c
// Size     : 374 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4014f06c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  
  (*(code *)&SUB_4008b530)(&DAT_3ffc8ad8,0,0x60);
  if (param_1 == 0) {
    FUN_40147fe4(1,1,1," config");
    return 0x102;
  }
  if (*(uint *)(param_1 + 0xd0) == 0x1f2f3f4f) {
    if ((*(int *)(param_1 + 8) != 0x6c) || (*(int *)(param_1 + 0xc) != 1)) {
      memw();
      FUN_40147fe4(1,1,1,"f range",0x6c,1,*(int *)(param_1 + 8),*(int *)(param_1 + 0xc));
      return 0x102;
    }
    uVar4 = *(uint *)(param_1 + 0x74);
    pcVar5 = "f range";
    uVar6 = uVar4;
    if (uVar4 - 2 < 0x1f) {
      uVar3 = *(uint *)(param_1 + 0x78);
      pcVar5 = "f range";
      uVar6 = uVar3;
      if ((int)uVar3 < 0x401) {
        uVar1 = *(uint *)(param_1 + 0x7c);
        if (uVar1 == 0) {
          if (0x3f < *(uint *)(param_1 + 0x80) - 1) {
            pcVar5 = "f range";
            uVar6 = *(uint *)(param_1 + 0x80);
            goto LAB_4014f0a9;
          }
        }
        else {
          pcVar5 = "f range";
          uVar6 = uVar1;
          if (uVar1 != 1) goto LAB_4014f0a9;
          if (0x7f < *(uint *)(param_1 + 0x84) - 1) {
            pcVar5 = "d error";
            uVar6 = *(uint *)(param_1 + 0x84);
            goto LAB_4014f0a9;
          }
        }
        uVar2 = *(uint *)(param_1 + 0xb8);
        if (uVar2 - 6 < 0x1b) {
          if ((*(int *)(param_1 + 0x98) == 0) ||
             (uVar6 = *(uint *)(param_1 + 0xac), uVar6 - 2 < 0x1f)) {
            uVar6 = *(uint *)(param_1 + 0xb0);
            if (uVar6 < 2) {
              _DAT_3ffc8b08 = *(undefined4 *)(param_1 + 0xac);
              _DAT_3ffc8ae4 = *(undefined4 *)(param_1 + 0x80);
              _DAT_3ffc8ae8 = *(undefined4 *)(param_1 + 0x84);
              _DAT_3ffc8b2c = *(undefined4 *)(param_1 + 0x88);
              _DAT_3ffc8b30 = *(undefined4 *)(param_1 + 0x8c);
              _DAT_3ffc8aec = *(undefined4 *)(param_1 + 0x90);
              _DAT_3ffc8af0 = *(undefined4 *)(param_1 + 0x94);
              _DAT_3ffc8af8 = *(undefined4 *)(param_1 + 0x9c);
              _DAT_3ffc8ad8 = uVar4;
              _DAT_3ffc8ae0 = uVar1;
              _DAT_3ffc8af4 = *(int *)(param_1 + 0x98);
              _DAT_3ffc8b24 = *(undefined4 *)(param_1 + 0xa0);
              _DAT_3ffc8adc = uVar3;
              _DAT_3ffc8afc = (uint)(*(int *)(param_1 + 0xa4) != 0);
              _DAT_3ffc8b14 = uVar2;
              _DAT_3ffc8b10 = *(undefined4 *)(param_1 + 0xb4);
              _DAT_3ffc8b0c = uVar6;
              _DAT_3ffc8b00 = (uint)(*(int *)(param_1 + 0xa8) != 0);
              _DAT_3ffc8b18 = *(undefined4 *)(param_1 + 0xc0);
              _DAT_3ffc8b1c = *(undefined4 *)(param_1 + 0xc4);
              _DAT_3ffc8b28 = *(undefined4 *)(param_1 + 0xcc);
              DAT_3ffc8b20 = *(undefined1 *)(param_1 + 200);
              memw();
              memw();
              return 0;
            }
            pcVar5 = "tion!\r\n";
          }
          else {
            pcVar5 = "e id %d";
          }
        }
        else {
          pcVar5 = "d error";
          uVar6 = uVar2;
        }
      }
    }
  }
  else {
    pcVar5 = "sion=%d";
    uVar6 = *(uint *)(param_1 + 0xd0);
  }
LAB_4014f0a9:
  FUN_40147fe4(1,1,1,pcVar5,uVar6);
  return 0x102;
}


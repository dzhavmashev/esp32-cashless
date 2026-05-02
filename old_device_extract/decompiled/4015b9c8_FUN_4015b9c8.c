// Function : FUN_4015b9c8
// Address  : 0x4015b9c8
// Size     : 932 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015b9c8(int *param_1)

{
  char cVar1;
  byte *pbVar2;
  code *pcVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined1 auStack_40 [16];
  int iStack_30;
  int iStack_2c;
  uint uStack_28;
  int iStack_24;
  
  piVar4 = _DAT_3ffca0b8;
  iStack_30 = _DAT_3ffc8804;
  iStack_2c = _DAT_3ffc8800;
  memw();
  pbVar2 = (byte *)FUN_4015b1c4();
  if (((_DAT_3ffc8864 != 0) && (memw(), DAT_3ffc1a3c == '\0')) && (memw(), DAT_3ffbfc50 != '\0')) {
    piVar4 = (int *)0x0;
  }
  uVar6 = 0xff;
  uVar7 = 0xff;
  if (param_1 != (int *)0x0) {
    uVar6 = (uint)*(byte *)((int)param_1 + 0xab);
    uVar7 = (uint)*(byte *)(param_1 + 0x2b);
  }
  uVar8 = (uint)*pbVar2;
  memw();
  FUN_40147fe4(1,4,4,0x3f4347d8,param_1,piVar4,uVar6,uVar7,uVar8);
  if ((piVar4 == param_1) && (piVar4 != (int *)0x0)) {
    if (*(byte *)((int)param_1 + 0xab) == *pbVar2) {
      _DAT_3ffca0c4 = _DAT_3ffca0c4 | 0x140;
      memw();
      FUN_40147fe4(1,4,4,0x3f4347c0,*(undefined1 *)(_DAT_3ffc8800 + 0x154),5,uVar6,uVar7,uVar8);
      *(undefined1 *)(_DAT_3ffc8800 + 0x154) = 5;
      memw();
      memw();
      return 0;
    }
  }
  else if (param_1 == (int *)0x0) {
    return 1;
  }
  FUN_4015fff0(0,param_1 + 1);
  FUN_40147fe4(1,0xc,4,0x3f4347a7,5);
  FUN_4015a448(5);
  if (((*_DAT_3ffbfc54 == 3) && (DAT_3ffc89d6 != '\0')) && (DAT_3ffc89d7 != '\x01')) {
    iStack_24 = _DAT_3ffc8804 + 0x100;
    memw();
    uStack_28 = (uint)*_DAT_3ffbfc54;
    FUN_40147fe4(1,4,3,0x3f435628,*(undefined1 *)(_DAT_3ffc8804 + 0x156),
                 *(undefined1 *)((int)param_1 + 0xab),uVar6,uVar7,uVar8);
    if ((*(char *)(iStack_24 + 0x56) != '\x0e' &&
         *(char *)(iStack_24 + 0x56) != *(char *)((int)param_1 + 0xab)) &&
       (*(char *)((int)param_1 + 0xab) != '\x0e')) {
      FUN_40147fe4(1,4,4,0x3f434772);
      DAT_3ffc89d7 = 1;
      memw();
      DAT_3ffc89d8 = (byte)uStack_28;
      memw();
      if (_DAT_3ffc8864 != 0) {
        DAT_3ffc89d8 = 0xf;
        memw();
        memw();
        FUN_40147fe4(1,0x8000,uStack_28,0x3f4355f9,*(undefined1 *)((int)param_1 + 0xab),
                     *(undefined1 *)(iStack_24 + 0x56),0xf);
        auStack_40[0] = *(undefined1 *)((int)param_1 + 0xab);
        memw();
        memw();
        FUN_40147270(0x23,auStack_40,1);
      }
      DAT_3ffc89d4 = *(undefined1 *)((int)param_1 + 0xab);
      memw();
      DAT_3ffc89d5 = (undefined1)param_1[0x2b];
      memw();
      memw();
      _DAT_3ffc7b08 = param_1;
      (**(code **)(_DAT_3ffc1a34 + 0xec))(0x3ffc7af4);
      (**(code **)(_DAT_3ffc1a34 + 0xf0))(0x3ffc7af4);
      (**(code **)(_DAT_3ffc1a34 + 0xf4))(0x3ffc7af4,0x4015b8f8,0);
      if (_DAT_3ffc8864 == 0) {
        iVar9 = (DAT_3ffc89d8 + 1) * (uint)*(ushort *)(param_1 + 10);
        pcVar3 = *(code **)(_DAT_3ffc1a34 + 0xe8);
      }
      else {
        iVar9 = (DAT_3ffc89d8 + 1) * (uint)*(ushort *)(_DAT_3ffbfc54 + 0x3f8);
        pcVar3 = *(code **)(_DAT_3ffc1a34 + 0xe8);
      }
      (*pcVar3)(0x3ffc7af4,iVar9,0);
      return 0;
    }
  }
  if (*(code **)(_DAT_3ffc89a4 + 0x5c) == (code *)0x0) {
    FUN_40147fe4(1,8,1,"");
  }
  else {
    iVar9 = 0;
    if ((char)param_1[0xcb] != '\0') {
      iVar9 = *(byte *)((int)param_1 + 0x32d) + 2;
    }
    (**(code **)(_DAT_3ffc89a4 + 0x5c))(param_1 + 0xcb,iVar9);
  }
  *(undefined2 *)((int)param_1 + 0x26) = 0;
  *(undefined1 *)(param_1 + 0x4d) = 4;
  memw();
  *(char *)(*param_1 + 0x157) = (char)param_1[0x2b];
  memw();
  *(undefined1 *)(*param_1 + 0x156) = *(undefined1 *)((int)param_1 + 0xab);
  memw();
  if ((iStack_2c == 0) || (iStack_2c != *param_1)) {
    memw();
    FUN_40147fe4(1,0x800,1,"ull bss","l_chm.c",0x427);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar5 = (int)param_1 + 0xab;
  iVar9 = iVar5;
  if (((iStack_30 != 0) &&
      (cVar1 = *(char *)(iStack_30 + 0x156), cVar1 == *(char *)((int)param_1 + 0xab))) &&
     ((char)param_1[0x2b] == '\0')) {
    if (*(char *)(iStack_30 + 0x157) == '\x01') {
      if (8 < (byte)(cVar1 - 1U)) goto LAB_4015bcc8;
    }
    else if ((8 < (byte)(cVar1 - 5U)) || (*(char *)(iStack_30 + 0x157) != '\x02'))
    goto LAB_4015bcc8;
    FUN_40147fe4(1,4,4,0x3f43473d);
    iVar9 = iStack_30 + 0x156;
  }
LAB_4015bcc8:
  (**(code **)(_DAT_3ffc1a34 + 0x19c))(1,0,1000000);
  FUN_4014b690(iVar9);
  (**(code **)(_DAT_3ffc1a34 + 0x1a0))(1);
  if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0)) {
    memw();
    _DAT_3ffca0c0 = _DAT_3ff73c00 + _DAT_3ffc1a30;
  }
  else {
    _DAT_3ffca0c0 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
  }
  if (*(byte *)((int)param_1 + 0xab) == *pbVar2) {
    FUN_4015b6ac(param_1,0);
  }
  else {
    memw();
    iVar9 = FUN_4015b18c(3,&DAT_4015b6a4,param_1);
    if (iVar9 != 0) {
      FUN_40147fe4(1,4,4,0x3f434727);
      return 1;
    }
    FUN_4015b52c(iVar5,0,0,&DAT_4015b6a4,0,param_1);
  }
  return 2;
}


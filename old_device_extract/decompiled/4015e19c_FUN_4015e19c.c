// Function : FUN_4015e19c
// Address  : 0x4015e19c
// Size     : 363 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015e19c(int *param_1)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  undefined1 auStack_30 [6];
  undefined1 uStack_2a;
  undefined1 uStack_29;
  
  if ((param_1 == (int *)0x0) || (iVar3 = *param_1, iVar3 == 0)) {
    FUN_40147fe4(1,0x800,1,"","l_chm.c",0x956);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  (**(code **)(_DAT_3ffc1a34 + 0xec))(param_1 + 0x4f);
  (**(code **)(_DAT_3ffc1a34 + 0xf0))(param_1 + 0x4f);
  if (param_1 == *(int **)(iVar3 + 0xec)) {
    return;
  }
  uVar2 = *(ushort *)((int)param_1 + 0x26) & 0x3fff;
  if ((*(ushort *)((int)param_1 + 0x26) & 0x3fff) == 0) {
    memw();
    FUN_40147fe4(1,4,3,0x3f4354ff,(char)param_1[1],*(undefined1 *)((int)param_1 + 5),
                 *(undefined1 *)((int)param_1 + 6),*(undefined1 *)((int)param_1 + 7),
                 (char)param_1[2],*(undefined1 *)((int)param_1 + 9),uVar2);
  }
  else {
    memw();
    FUN_40147fe4(1,4,3,0x3f435556,(char)param_1[1],*(undefined1 *)((int)param_1 + 5),
                 *(undefined1 *)((int)param_1 + 6),*(undefined1 *)((int)param_1 + 7),
                 (char)param_1[2],*(undefined1 *)((int)param_1 + 9),uVar2,param_1[3],param_1);
  }
  if (_DAT_3ffc8864 != 0) {
    if (*(char *)((int)param_1 + 0x2f9) == '\0') {
      *(char *)(*(int *)(iVar3 + 0xec) + 0x2fa) = *(char *)(*(int *)(iVar3 + 0xec) + 0x2fa) + '\x01'
      ;
      memw();
    }
    else {
      (*(code *)&SUB_4008b3d0)(auStack_30,param_1 + 1,6);
      uStack_2a = (undefined1)*(undefined2 *)((int)param_1 + 0x26);
      uStack_29 = 1;
      memw();
      memw();
      FUN_40147240(0xf,auStack_30,8);
    }
  }
  if ((param_1[3] & 1U) != 0) {
    sVar1 = *(short *)((int)param_1 + 0x26);
    if (sVar1 == 0) goto LAB_4015e305;
    if ((_DAT_3ffc8864 == 0) || (*(char *)((int)param_1 + 0x2f9) == '\0')) {
      memw();
      (*(code *)&SUB_4008b3d0)(auStack_30,param_1 + 1,6);
      uStack_2a = (undefined1)sVar1;
      uStack_29 = 0;
      memw();
      memw();
      FUN_40147240(0xf,auStack_30,8);
    }
  }
  FUN_4015dcd0(0,param_1);
  _DAT_3ffc899c =
       (ushort)(0xfffffffefffffffe >> 0x20 - (*(ushort *)((int)param_1 + 0x26) & 0x1f)) &
       _DAT_3ffc899c;
  *(undefined2 *)((int)param_1 + 0x26) = 0;
  memw();
  if (param_1 != *(int **)(iVar3 + 0xec)) {
    param_1[3] = param_1[3] & 0xfffffffe;
  }
  memw();
  FUN_4014b690(0);
LAB_4015e305:
  FUN_4015d80c(param_1);
  return;
}


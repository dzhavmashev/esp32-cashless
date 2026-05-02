// Function : FUN_40159330
// Address  : 0x40159330
// Size     : 349 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40159330(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = _DAT_3ffc8800;
  iVar2 = *(int *)(_DAT_3ffc8800 + 0xe4);
  if (iVar2 == 0) {
    FUN_40147fe4(1,0x10004,2,0x3f436be2);
    return;
  }
  if (*(int *)(iVar2 + 0x300) == 0) {
    memw();
    FUN_40147fe4(1,0x40,3,0x3f434f30,*(undefined1 *)(iVar2 + 4),*(undefined1 *)(iVar2 + 5),
                 *(undefined1 *)(iVar2 + 6),*(undefined1 *)(iVar2 + 7),*(undefined1 *)(iVar2 + 8),
                 *(undefined1 *)(iVar2 + 9));
    *(undefined1 *)(iVar2 + 0x2fb) = 1;
    memw();
    iVar3 = iVar1 + 0x40;
    memw();
    (**(code **)(_DAT_3ffc1a34 + 0xec))(iVar3);
    (**(code **)(_DAT_3ffc1a34 + 0xf0))(iVar3);
    (**(code **)(_DAT_3ffc1a34 + 0xf4))(iVar3,0x40157494,0);
    iVar4 = iVar1 + 0x2c;
    (**(code **)(_DAT_3ffc1a34 + 0xe8))(iVar3,0x400,0);
    (**(code **)(_DAT_3ffc1a34 + 0xec))(iVar4);
    (**(code **)(_DAT_3ffc1a34 + 0xf0))(iVar4);
    (**(code **)(_DAT_3ffc1a34 + 0xf4))(iVar4,0x40157484,0);
    (**(code **)(_DAT_3ffc1a34 + 0xe8))(iVar4,200,1);
  }
  if (*(int *)(iVar2 + 0x300) == 0) {
    (**(code **)(_DAT_3ffc1a34 + 0x144))(iVar2 + 0x2fc,2);
    *(ushort *)(iVar2 + 0x2fc) = *(ushort *)(iVar2 + 0x2fc) % 0xfff5;
    memw();
    memw();
  }
  else {
    if (*(int *)(iVar2 + 0x300) == 10) {
      (**(code **)(_DAT_3ffc1a34 + 0xec))(iVar1 + 0x40);
      (**(code **)(_DAT_3ffc1a34 + 0xf0))(iVar1 + 0x40);
      FUN_401592b4();
      return;
    }
    *(short *)(iVar2 + 0x2fc) = *(short *)(iVar2 + 0x2fc) + 1;
    memw();
  }
  memw();
  FUN_4015ebb4(iVar2,8,0,iVar2 + 0x2fc);
  *(int *)(iVar2 + 0x300) = *(int *)(iVar2 + 0x300) + 1;
  memw();
  return;
}


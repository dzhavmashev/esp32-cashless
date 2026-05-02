// Function : FUN_40162bb8
// Address  : 0x40162bb8
// Size     : 135 bytes


void FUN_40162bb8(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  bVar2 = *(byte *)(param_1 + 1) & 3;
  if (bVar2 == 2) {
    (*(code *)&SUB_4008b3d0)(param_2,param_1 + 4,6);
    iVar1 = param_1 + 0x10;
  }
  else if (bVar2 == 3) {
    (*(code *)&SUB_4008b3d0)(param_2,param_1 + 0x10,6);
    iVar1 = param_1 + 0x18;
  }
  else {
    iVar1 = param_1 + 10;
    iVar3 = param_1 + 4;
    if (bVar2 == 1) {
      iVar3 = param_1 + 0x10;
    }
    (*(code *)&SUB_4008b3d0)(param_2,iVar3,6);
  }
  (*(code *)&SUB_4008b3d0)(param_2 + 6,iVar1,6);
  iVar1 = FUN_40186b68(param_1);
  if (iVar1 == 0x10) {
    *(undefined1 *)(param_2 + 0xc) = 0;
    memw();
    memw();
  }
  else {
    *(char *)(param_2 + 0xc) = (char)iVar1;
  }
  *(undefined1 *)(param_2 + 0xd) = 0;
  *(undefined1 *)(param_2 + 0xe) = 0;
  *(undefined1 *)(param_2 + 0xf) = 0;
  memw();
  memw();
  return;
}


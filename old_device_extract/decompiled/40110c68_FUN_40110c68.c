// Function : FUN_40110c68
// Address  : 0x40110c68
// Size     : 117 bytes


char FUN_40110c68(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  ushort uVar4;
  
  if (param_1 == 0) {
    (*(code *)&SUB_40094c54)("lid pcb",0x7ea,"_header","mote_ip");
  }
  uVar2 = FUN_40109eec(*(undefined4 *)(param_1 + 0x7c));
  iVar3 = FUN_401102e0(param_1,0,uVar2);
  if (iVar3 == 0) {
    cVar1 = -2;
    *(ushort *)(param_1 + 0x46) = *(ushort *)(param_1 + 0x46) | 3;
    memw();
  }
  else {
    FUN_40110330();
    cVar1 = FUN_40110224(param_1,iVar3,param_1,param_1 + 0x18);
    if (cVar1 == '\0') {
      uVar4 = *(ushort *)(param_1 + 0x46) & 0xfffc;
    }
    else {
      uVar4 = *(ushort *)(param_1 + 0x46) | 3;
    }
    *(ushort *)(param_1 + 0x46) = uVar4;
    memw();
    memw();
  }
  memw();
  return cVar1;
}


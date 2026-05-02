// Function : FUN_40110224
// Address  : 0x40110224
// Size     : 142 bytes


undefined1 FUN_40110224(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined1 uVar5;
  
  if (param_2 == 0) {
    (*(code *)&SUB_40094c54)("lid pcb",0x787,"pty_ack","tcp_hdr");
  }
  iVar3 = FUN_401101f4(param_1,param_3,param_4);
  uVar1 = 0xfc;
  if (iVar3 != 0) {
    iVar4 = *(int *)(param_2 + 4);
    uVar2 = FUN_4011dc38(param_2,6,*(undefined2 *)(param_2 + 8),param_3,param_4);
    uVar1 = 0x40;
    *(char *)(iVar4 + 0x10) = (char)uVar2;
    *(char *)(iVar4 + 0x11) = (char)((ushort)uVar2 >> 8);
    memw();
    uVar5 = 0;
    if (param_1 != 0) {
      uVar1 = *(undefined1 *)(param_1 + 0x33);
      uVar5 = *(undefined1 *)(param_1 + 0x32);
    }
    if ((param_4 == 0) || (*(char *)(param_4 + 0x14) != '\x06')) {
      memw();
      uVar1 = FUN_40116d00(param_2,param_3,param_4,uVar1,uVar5,6,iVar3);
    }
    else {
      memw();
      uVar1 = FUN_40117f9c(param_2,param_3,param_4);
    }
  }
  FUN_4010bb10(param_2);
  return uVar1;
}


// Function : FUN_4010b840
// Address  : 0x4010b840
// Size     : 125 bytes


void FUN_4010b840(int param_1,uint param_2,byte param_3)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar4;
  char *pcVar5;
  uint uVar3;
  
  uVar3 = param_2 & 0xff;
  cVar2 = (char)param_2;
  if (param_1 != 0) goto LAB_4010b85d;
  pcVar5 = "!= NULL";
  uVar4 = 0x590;
  while( true ) {
    (*(code *)&SUB_40094c54)("d netif",uVar4,"r_match",pcVar5);
    cVar2 = (char)uVar3;
LAB_4010b85d:
    uVar3 = (uint)cVar2;
    if ((int)uVar3 < 3) break;
    pcVar5 = "!= NULL";
    uVar4 = 0x591;
  }
  bVar1 = *(byte *)(param_1 + uVar3 + 0x94);
  if (bVar1 != param_3) {
    if ((*(byte *)(param_1 + 0xeb) & 0x40) != 0) {
      FUN_4011a95c(param_1,uVar3,param_3);
    }
    if (((bVar1 & 0x10) != 0) && ((param_3 & 0x10) == 0)) {
      FUN_4010b08c(param_1 + uVar3 * 0x18 + 0x4c,0);
    }
    *(byte *)(param_1 + uVar3 + 0x94) = param_3;
    memw();
    if (((bVar1 & 0x10) == 0) && ((param_3 & 0x10) != 0)) {
      memw();
      FUN_4010b1a0(param_1,2);
    }
  }
  return;
}


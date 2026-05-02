// Function : FUN_4010c020
// Address  : 0x4010c020
// Size     : 111 bytes


undefined4 FUN_4010c020(int *param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  
  param_3 = param_3 & 0xffff;
  if ((param_2 == 0) || (param_1 == (int *)0x0)) {
    uVar5 = 0xf0;
  }
  else {
    if (param_3 <= *(ushort *)((int)param_1 + 8)) {
      uVar1 = 0;
      uVar2 = param_3;
      do {
        if (uVar2 == 0) {
          if (uVar1 == param_3) {
            return 0;
          }
          pcVar7 = "id pbuf";
          uVar5 = 0x4f3;
          param_1 = (int *)0x0;
LAB_4010c060:
          (*(code *)&SUB_40094c54)("if_init",uVar5,"take_at",pcVar7);
        }
        else if (param_1 == (int *)0x0) {
          pcVar7 = "om->len";
          uVar5 = 0x4e8;
          goto LAB_4010c060;
        }
        uVar3 = (uint)*(ushort *)((int)param_1 + 10);
        iVar6 = param_2 + uVar1;
        iVar4 = (uVar3 < uVar2) * uVar3 + (uVar3 >= uVar2) * uVar2;
        uVar2 = uVar2 - iVar4;
        uVar1 = uVar1 + iVar4;
        (*(code *)&SUB_4008b3d0)(param_1[1],iVar6,iVar4);
        param_1 = (int *)*param_1;
      } while( true );
    }
    uVar5 = 0xff;
  }
  return uVar5;
}


// Function : FUN_40100618
// Address  : 0x40100618
// Size     : 117 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40100618(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *in_t0;
  
  iVar1 = FUN_40100598();
  piVar2 = _DAT_3ffc5858;
  if (iVar1 == 0) {
    for (; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[1]) {
      if (*piVar2 == param_1) {
        piVar4 = _DAT_3ffc5858;
        if (piVar2 != _DAT_3ffc5858) goto LAB_40100664;
        _DAT_3ffc5858 = (int *)piVar2[1];
        while (_DAT_3ffc5854 == 0) {
          memw();
          piVar2 = (int *)(*(code *)&SUB_40094c54)
                                    ("p_netif/esp_netif_objects.c",0x6f,"ith %d\n","nnected");
          piVar4 = in_t0;
LAB_40100664:
          do {
            piVar3 = piVar4;
            piVar4 = (int *)piVar3[1];
          } while (piVar4 != piVar2);
          piVar3[1] = piVar2[1];
          memw();
        }
        _DAT_3ffc5854 = _DAT_3ffc5854 + -1;
        memw();
        (*(code *)&SUB_40094d80)();
        FUN_401005b0();
        return 0;
      }
    }
    FUN_401005b0();
    iVar1 = 0x105;
  }
  return iVar1;
}

